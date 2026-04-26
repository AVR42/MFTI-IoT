/*
 * С1.с
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
#include <string.h>

int main() {
    char s1[10001], s2[10001];
    
    // Читаем две строки
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    
    // Удаляем символ новой строки, если есть
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';
    
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    
    // Первое число: длина наибольшего префикса s1, являющегося суффиксом s2
    int first = 0;
    for (int len = 1; len <= len1 && len <= len2; len++) {
        // Проверяем, является ли префикс s1 длины len суффиксом s2
        int match = 1;
        for (int i = 0; i < len; i++) {
            // Сравниваем i-й символ префикса s1 с (len2 - len + i)-м символом s2
            if (s1[i] != s2[len2 - len + i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            first = len;
        }
    }
    
    // Второе число: длина наибольшего суффикса s1, являющегося префиксом s2
    int second = 0;
    for (int len = 1; len <= len1 && len <= len2; len++) {
        // Проверяем, является ли суффикс s1 длины len префиксом s2
        int match = 1;
        for (int i = 0; i < len; i++) {
            // Сравниваем (len1 - len + i)-й символ суффикса s1 с i-м символом префикса s2
            if (s1[len1 - len + i] != s2[i]) {
                match = 0;
                break;
            }
        }
        if (match) {
            second = len;
        }
    }
    
    printf("%d %d\n", first, second);
    
    return 0;
}
