/*
 * С2.с
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

int stack[1000];  // стек для чисел
int top = -1;     // вершина стека

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char s[100];
    int a, b;
    
    while (scanf("%s", s) != EOF) {
        if (s[0] >= '0' && s[0] <= '9') {
            // это число
            push(atoi(s));
        } else {
            // это оператор
            b = pop();
            a = pop();
            
            if (s[0] == '+') push(a + b);
            if (s[0] == '-') push(a - b);
            if (s[0] == '*') push(a * b);
            if (s[0] == '/') push(a / b);
        }
    }
    
    printf("%d\n", pop());
    return 0;
}
