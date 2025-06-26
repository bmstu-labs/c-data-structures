#include "queue.h"
#include "errors.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    queue q;
    int status;

    // Инициализация очереди
    status = queue_init(&q);
    assert(status == OK);

    // Проверка очереди на пустоту
    assert(queue_is_empty(&q) == TRUE);

    // Добавление элементов в очередь
    status = queue_push(&q, "First element");
    assert(status == OK);
    status = queue_push(&q, "Second element");
    assert(status == OK);
    status = queue_push(&q, "Third element");
    assert(status == OK);

    // Проверка размера очереди
    assert(queue_size(&q) == 3);

    // Просмотр элемента в начале очереди
    void *peek_result = queue_peek(&q);
    printf("peek: %s\n", peek_result);

    // Удаление элементов из очереди
    void *pop_result = queue_pop(&q);
    printf("pop: %s\n", pop_result);

    pop_result = queue_pop(&q);
    printf("pop: %s\n", pop_result);

    pop_result = queue_pop(&q);
    printf("pop: %s\n", pop_result);

    pop_result = queue_pop(&q);
    assert(pop_result == NULL);

    printf("size is %lu\n", queue_size(&q));

    // Проверка очереди на пустоту после удаления всех элементов
    assert(queue_is_empty(&q) == TRUE);

    // // Освобождение памяти, выделенной под очередь
    status = queue_free(&q);
    assert(status == OK);

    printf("All tests passed successfully.\n");
    return 0;
}
