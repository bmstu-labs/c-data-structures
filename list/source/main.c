

#include <stdio.h>
#include <stdlib.h>

// Предположим, что структуры list и node определены следующим образом:
struct list {
    struct node *head;
    size_t size;
};

struct node {
    void *data;
    struct node *next;
};

// Определяем константы для статуса
#define OK 0
#define NULLPTR_GIVEN -1
#define ALLOCATION_ERROR -2
#define NEXT_NODE_NOT_EMPTY -3
#define TRUE 1
#define FALSE 0

// Прототипы функций
int list_init(struct list *l);
int list_push_back(struct list *restrict l, void *restrict data);
int list_push_front(struct list *restrict l, void *restrict data);
void *list_get(struct list *l, size_t index);
void *list_head(struct list *l);
void *list_tail(struct list *l);
int list_empty(const struct list *l);
int list_free(struct list *l);
int node_init(struct node *restrict n, const void *restrict data);
int node_free(struct node *restrict n);

int main() {
    struct list my_list;
    int status;

    // Тест list_init
    status = list_init(&my_list);
    if (status != OK) {
        printf("list_init failed\n");
        return EXIT_FAILURE;
    }

    // Тест list_push_back
    status = list_push_back(&my_list, "First element");
    if (status != OK) {
        printf("list_push_back failed\n");
        return EXIT_FAILURE;
    }
    status = list_push_back(&my_list, "Second element");
    if (status != OK) {
        printf("list_push_back failed\n");
        return EXIT_FAILURE;
    }

    // Тест list_push_front
    status = list_push_front(&my_list, "Front element");
    if (status != OK) {
        printf("list_push_front failed\n");
        return EXIT_FAILURE;
    }

    // Тест list_get
    void *first_element = list_get(&my_list, 0);
    void *second_element = list_get(&my_list, 1);
    void *third_element = list_get(&my_list, 2);
    if (first_element != "Front element" || second_element != "First element" || third_element != "Second element") {
        printf("list_get failed\n");
        return EXIT_FAILURE;
    }

    // Тест list_head
    void *head = list_head(&my_list);
    if (head != "Front element") {
        printf("list_head failed\n");
        return EXIT_FAILURE;
    }

    // Тест list_tail
    void *tail = list_tail(&my_list);
    if (tail != "Second element") {
        printf("list_tail failed\n");
        return EXIT_FAILURE;
    }

    // Тест list_empty
    if (list_empty(&my_list) == TRUE) {
        printf("list_empty failed\n");
        return EXIT_FAILURE;
    }

    // Тест list_free
    status = list_free(&my_list);
    if (status != OK) {
        printf("list_free failed\n");
        return EXIT_FAILURE;
    }

    printf("All tests passed\n");
    return EXIT_SUCCESS;
}