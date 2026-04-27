#include <stdio.h>
#include <stdlib.h>

// Структура для очереди
typedef struct QueueNode {
    struct tree *node;
    int hd;
    struct QueueNode *next;
} QueueNode;

typedef struct {
    QueueNode *front;
    QueueNode *rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue *q) {
    return q->front == NULL;
}

void enqueue(Queue *q, struct tree *node, int hd) {
    QueueNode *newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->hd = hd;
    newNode->next = NULL;
    
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

QueueNode* dequeue(Queue *q) {
    if (isEmpty(q)) return NULL;
    
    QueueNode *temp = q->front;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    return temp;
}

void btUpView(struct tree *root) {
    if (root == NULL) return;
    
    // Массивы для хранения результатов
    int values[100];
    int hd_values[100];
    int count = 0;
    
    Queue q;
    initQueue(&q);
    
    // Начинаем с корня (горизонтальное расстояние 0)
    enqueue(&q, root, 0);
    
    while (!isEmpty(&q)) {
        QueueNode *current = dequeue(&q);
        struct tree *node = current->node;
        int hd = current->hd;
        
        // Проверяем, есть ли уже узел с таким горизонтальным расстоянием
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (hd_values[i] == hd) {
                found = 1;
                break;
            }
        }
        
        // Если нет - добавляем (это будет самый верхний узел для этого hd)
        if (!found) {
            hd_values[count] = hd;
            values[count] = node->key;
            count++;
        }
        
        // Добавляем детей в очередь
        if (node->left != NULL) {
            enqueue(&q, node->left, hd - 1);
        }
        if (node->right != NULL) {
            enqueue(&q, node->right, hd + 1);
        }
        
        free(current);
    }
    
    // Сортируем результаты по горизонтальному расстоянию
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (hd_values[j] > hd_values[j + 1]) {
                // Меняем расстояния
                int temp_hd = hd_values[j];
                hd_values[j] = hd_values[j + 1];
                hd_values[j + 1] = temp_hd;
                
                // Меняем значения
                int temp_val = values[j];
                values[j] = values[j + 1];
                values[j + 1] = temp_val;
            }
        }
    }
    
    // Выводим результат
    for (int i = 0; i < count; i++) {
        printf("%d ", values[i]);
    }
}
