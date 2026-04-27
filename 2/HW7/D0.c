/*
 * D0.c
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
#include <string.h>

struct list {
    char word[20];
    struct list *next;
};

// Добавление слова в список (в начало)
void add_to_list(struct list **head, char *word) {
    struct list *new_node = (struct list*)malloc(sizeof(struct list));
    strcpy(new_node->word, word);
    new_node->next = *head;
    *head = new_node;
}

// Вывод списка
void print_list(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        printf("%s", current->word);
        if (current->next != NULL) {
            printf(" ");
        }
        current = current->next;
    }
    printf("\n");
}

// Удаление списка
void delete_list(struct list *head) {
    struct list *current = head;
    while (current != NULL) {
        struct list *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    char str[1000];
    char *word;
    struct list *head = NULL;
    struct list *i, *j;
    char temp[20];
    
    // Читаем строку
    fgets(str, 1000, stdin);
    
    // Убираем точку в конце
    str[strlen(str) - 2] = '\0';
    
    // Разбиваем на слова и добавляем в список
    word = strtok(str, " ");
    while (word != NULL) {
        add_to_list(&head, word);
        word = strtok(NULL, " ");
    }
    
    // Сортировка пузырьком (меняем местами данные в узлах)
    for (i = head; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (strcmp(i->word, j->word) > 0) {
                strcpy(temp, i->word);
                strcpy(i->word, j->word);
                strcpy(j->word, temp);
            }
        }
    }
    
    // Выводим
    print_list(head);
    
    // Удаляем список
    delete_list(head);
    
    return 0;
}
