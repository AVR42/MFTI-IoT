#include <stdint.h>
#include <stddef.h>

// Саму структуру в файл решения копировать не обязательно, 
// если автотест проверяет только тело функции.
// Но она должна соответствовать описанию:
/*
typedef struct list {
    uint64_t address;
    size_t size;
    char comment[64];
    struct list *next;
} list;
*/

uint64_t findMaxBlock(list *head) {
    // Если список пустой, возвращаем 0 согласно условию
    if (head == NULL) {
        return 0;
    }

    // Инициализируем переменные данными из первого узла
    size_t maxSize = head->size;
    uint64_t maxAddress = head->address;
    
    // Указатель для итерации по списку
    list *current = head->next;

    while (current != NULL) {
        // Если нашли блок больше текущего максимума
        if (current->size > maxSize) {
            maxSize = current->size;
            maxAddress = current->address;
        }
        // Переходим к следующему элементу
        current = current->next;
    }

    return maxAddress;
}
