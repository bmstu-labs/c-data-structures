#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "node.h"
#include "errors.h"

int main(void) {
    struct list my_list;
    if (list_init(&my_list) != OK) {
        fprintf(stderr, "Failed to initialize list\n");
        return 1;
    }

    // Создаём несколько узлов с динамическими данными
    for (int i = 0; i < 3; i++) {
        // Выделяем строку
        char *data = malloc(16);
        if (!data) {
            perror("malloc");
            return 1;
        }

        snprintf(data, 16, "value_%d", i);

        struct node *n = malloc(sizeof(struct node));
        if (!n) {
            perror("malloc");
            free(data);
            return 1;
        }

        if (node_init(n, data) != OK) {
            fprintf(stderr, "Failed to init node\n");
            free(data);
            free(n);
            return 1;
        }

        // Добавляем узел в конец списка
        if (list_push_back(&my_list, n) != OK) {
            fprintf(stderr, "Failed to push back\n");
            free(data);
            free(n);
            return 1;
        }
    }

    // Печатаем содержимое списка
    printf("List contents:\n");
    for (size_t i = 0; i < my_list.size; i++) {
        struct node *n = list_get(&my_list, i);
        if (n && n->data) {
            printf("  [%zu] %s\n", i, (char *)n->data);
        }
    }

    // Проверка head/tail
    struct node *head = list_head(&my_list);
    struct node *tail = list_tail(&my_list);

    if (head && head->data) printf("Head: %s\n", (char *)head->data);
    if (tail && tail->data) printf("Tail: %s\n", (char *)tail->data);

    // Очистка списка
    if (list_free(&my_list) != OK) {
        fprintf(stderr, "Failed to free list\n");
        return 1;
    }

    printf("List successfully freed.\n");
    return 0;
}
