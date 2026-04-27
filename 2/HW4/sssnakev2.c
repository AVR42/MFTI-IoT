/*
 * sssnake.c
 * 
 * Copyright 2026 litki <litki@LVM>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <inttypes.h>
#include <string.h>
#include <unistd.h>

#define MIN_Y  2
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME=KEY_F(10)};
enum {MAX_TAIL_SIZE=100, START_TAIL_SIZE=3, MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};


// Здесь храним коды управления змейкой
struct control_buttons
{
    int down;
    int up;
    int left;
    int right;
}control_buttons;

struct control_buttons default_controls = {KEY_DOWN, KEY_UP, KEY_LEFT, KEY_RIGHT};

/*
 Голова змейки содержит в себе
 x,y - координаты текущей позиции
 direction - направление движения
 tsize - размер хвоста
 *tail -  ссылка на хвост
 */
typedef struct snake_t
{
    int x;
    int y;
    int direction;
    size_t tsize;
    struct tail_t *tail;
    struct control_buttons controls;
} snake_t;

/*
 Хвост это массив состоящий из координат x,y
 */
typedef struct tail_t
{
    int x;
    int y;
} tail_t;

void initTail(struct tail_t t[], size_t size)
{
    struct tail_t init_t={0,0};
    for(size_t i=0; i<size; i++)
    {
        t[i]=init_t;
    }
}
void initHead(struct snake_t *head, int x, int y)
{
    head->x = x;
    head->y = y;
    head->direction = RIGHT;
}

void initSnake(snake_t *head, size_t size, int x, int y)
{
tail_t*  tail  = (tail_t*) malloc(MAX_TAIL_SIZE*sizeof(tail_t));
    initTail(tail, MAX_TAIL_SIZE);
    initHead(head, x, y);
    head->tail = tail; // прикрепляем к голове хвост
    head->tsize = size+1;
    head->controls = default_controls;
}

/*
 Движение головы с учетом текущего направления движения
 */

void go(struct snake_t *head)
{
    char ch = '@';
    int max_x=0, max_y=0;
    getmaxyx(stdscr, max_y, max_x); // Получаем текущий размер терминала

    mvprintw(head->y, head->x, " "); // Очищаем старое положение головы

    switch (head->direction)
    {
        case LEFT:
            if(head->x <= 0) 
                head->x = max_x; // Если ушли за левый край, появляемся справа
            --(head->x);
        break;

        case RIGHT:
            if(head->x >= max_x - 1) 
                head->x = -1; // Если ушли за правый край, появляемся слева
            ++(head->x);
        break;

        case UP:
            if(head->y <= MIN_Y) // MIN_Y у тебя равен 2 (там подсказка)
                head->y = max_y; 
            --(head->y);
        break;

        case DOWN:
            if(head->y >= max_y - 1) 
                head->y = MIN_Y - 1; 
            ++(head->y);
        break;
    }

    mvprintw(head->y, head->x, "%c", ch); // Рисуем голову в новой позиции
    refresh();
}

void changeDirection(struct snake_t* snake, const int32_t key)
{
    if (key == snake->controls.down && snake->direction != UP)
        snake->direction = DOWN;
    else if (key == snake->controls.up && snake->direction != DOWN)
        snake->direction = UP;
    else if (key == snake->controls.right && snake->direction != LEFT)
        snake->direction = RIGHT;
    else if (key == snake->controls.left && snake->direction != RIGHT)
        snake->direction = LEFT;
}

/*
 Движение хвоста с учетом движения головы
 */
void goTail(struct snake_t *head)
{
    char ch = '*';
    mvprintw(head->tail[head->tsize-1].y, head->tail[head->tsize-1].x, " ");
    for(size_t i = head->tsize-1; i>0; i--)
    {
        head->tail[i] = head->tail[i-1];
        if( head->tail[i].y || head->tail[i].x)
            mvprintw(head->tail[i].y, head->tail[i].x, "%c", ch);
    }
    head->tail[0].x = head->x;
    head->tail[0].y = head->y;
}

// Проверка: врезалась ли голова в хвост
int isCrashing(struct snake_t *head)
{
    // Проходим по всем сегментам хвоста
    // Начинаем с 1, так как 0-й элемент хвоста всегда совпадает с головой
    for (size_t i = 1; i < head->tsize; i++)
    {
        if (head->x == head->tail[i].x && head->y == head->tail[i].y)
        {
            return 1; // Столкновение произошло
        }
    }
    return 0; // Все чисто
}

int main()
{
    snake_t* snake = (snake_t*)malloc(sizeof(snake_t));
    initSnake(snake, START_TAIL_SIZE, 10, 10);
    
    initscr();
    keypad(stdscr, TRUE);
    raw();
    noecho();
    curs_set(FALSE);
    
    mvprintw(0, 0, "Use arrows for control. Press 'F10' for EXIT");
    
    // Делаем getch() неблокирующим навсегда
    timeout(0); 

    int key_pressed = 0;
    int crashed = 0;
    
    // Переменные для контроля времени
    clock_t last_time = clock();
    double delay = 0.1; // Задержка в секундах (100 мс)

    while( key_pressed != STOP_GAME && !crashed )
    {
        key_pressed = getch(); // Опрашиваем клавишу (мгновенно)
        changeDirection(snake, key_pressed); // Сразу меняем направление

        // Проверяем, прошло ли достаточно времени для следующего шага
        if (((double)(clock() - last_time) / CLOCKS_PER_SEC) >= delay)
        {
            go(snake);
            goTail(snake);
            
            if (isCrashing(snake)) 
            {
                crashed = 1;
            }
            
            last_time = clock(); // Сбрасываем счетчик времени
        }
    }

    if (crashed)
    {
        // Для сообщения об ошибке можно вернуть блокирующий режим
        timeout(-1); 
        mvprintw(12, 10, "GAME OVER! Press any key to exit...");
        refresh();
        getch();
    }

    free(snake->tail);
    free(snake);
    endwin();
    return 0;
}

