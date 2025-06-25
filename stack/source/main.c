#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "errors.h"

// Добавим, если еще не определено
int stack_push(struct stack *s, const void *data);

int main(void) {
    struct stack s;

    // Инициализация стека
    if (stack_init(&s) != OK) {
        fprintf(stderr, "Ошибка: не удалось инициализировать стек\n");
        return 1;
    }

    // Создаем данные
    char *str1 = strdup("Hello");
    char *str2 = strdup("World");

    // Push элементов
    stack_push(&s, str1);
    stack_push(&s, str2);

    printf("Размер стека: %zu\n", s.size);

    // Peek
    struct node *top = stack_peek(&s);
    if (top) {
        printf("Верхушка: %s\n", (char *)top->data);
    }

    // Pop
    struct node *popped = stack_pop(&s);
    if (popped) {
        printf("Извлечено: %s\n", (char *)popped->data);
        free((void *)popped->data);  // освободим строку
        free(popped);                // освободим узел
    }

    printf("Размер после pop: %zu\n", s.size);

    // Free оставшегося
    stack_free(&s);

    return 0;
}
