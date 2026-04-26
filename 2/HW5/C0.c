/*
 * С0
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
    char N[1000];  // массив для хранения числа как строки
    scanf("%s", N);
    
    int len = strlen(N);
    int used[1000] = {0};  // для отметки использованных позиций
    int count = 0;

    // Перебираем все комбинации позиций i < j < k
    for (int i = 0; i < len; i++) {
        // Первая цифра не может быть '0'
        if (N[i] == '0') continue;
        
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                // Формируем число из цифр на позициях i, j, k
                int num = (N[i] - '0') * 100 + (N[j] - '0') * 10 + (N[k] - '0');
                
                // Проверяем, не встречалось ли уже такое число
                int already = 0;
                for (int t = 0; t < count; t++) {
                    if (used[t] == num) {
                        already = 1;
                        break;
                    }
                }
                
                if (!already) {
                    used[count] = num;
                    count++;
                }
            }
        }
    }
    
    printf("%d\n", count);
    
    return 0;
}

