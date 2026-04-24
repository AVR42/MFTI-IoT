/*
 * B1
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


#include <stddef.h>

/* 
Структура из условия:
typedef struct list {
    void *address;
    size_t size;
    char comment[64];
    struct list *next;
} list;
*/

size_t totalMemoryUsage(list *head) {
    size_t total = 0;
    list *current = head;

    // Проходим по списку, пока не встретим NULL
    while (current != NULL) {
        // Суммируем размер текущего блока
        total += current->size;
        // Переходим к следующему элементу
        current = current->next;
    }

    return total;
}

