#include "node.h"
#include "errors.h"

#include <stdlib.h>
#include <unitypes.h>

int node_init(struct node *restrict n, const void *restrict data) {
    int status = OK;

    if (n == NULL) {
        status = NULLPTR;
        return status;
    }

    n->data = data;
    n->next = NULL;

    return status;
}

int node_free(struct node *restrict n) {
    int status = OK;

    struct node *current = n;
    while (current) {
        struct node *next = current->next;

        free(current->data);
        free(current);

        current = next;
    }

    return status;
}