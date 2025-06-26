#include "tree.h"
#include "errors.h"

#include <stdio.h>

int int_cmp(const void *a, const void *b) {
    int diff = *((int *)a) - *((int *)b);
    if (diff > 0) {
        return 1;
    } else if (diff < 0) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    tree t;
    tree_init(&t);

    int a = 5;
    int b = 4;
    int c = 6;
    int d = 2;
    int e = 7;

    tree_insert(&t, (void *)&a, int_cmp);
    tree_insert(&t, (void *)&b, int_cmp);
    tree_insert(&t, (void *)&c, int_cmp);
    tree_insert(&t, (void *)&d, int_cmp);
    tree_insert(&t, (void *)&e, int_cmp);

    printf("Size of tree is %lu\n", tree_size(&t));

    const node *found_node_BFS = tree_BFS(&t, &c, int_cmp);
    if (found_node_BFS != NULL) {
        printf("Found element with value %d using BFS\n", *(int *)found_node_BFS->data);
    } else {
        printf("Element not found using BFS\n");
    }

    const node *found_node_DFS = tree_DFS(&t, &d, int_cmp);
    if (found_node_DFS != NULL) {
        printf("Found element with value %d using DFS\n", *(int *)found_node_DFS->data);
    } else {
        printf("Element not found using DFS\n");
    }

    tree_free(&t);

    return 0;
}
