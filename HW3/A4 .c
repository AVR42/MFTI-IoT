/*
 * 3.0.c
 * 
 * Copyright 2025 RRR <rrr@rrr-82nl>
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


int main() {
    int num1, num2, num3, summ, X;
    
        scanf("%d %d %d", &num1, &num2, &num3);
        summ = (num1 + num2 + num3);
    	X = (num1 * num2 * num3);
    	printf("%d+%d+%d=%d\n", num1, num2, num3, summ);
		printf("%d*%d*%d=%d\n", num1, num2, num3, X);

    return 0;
}

