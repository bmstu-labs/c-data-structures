#include "node.h"
#include "errors.h"

#include <stdlib.h>

int node_init(node *restrict n, const void *restrict data) {
    int status = OK;
    if (n == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    n->next = NULL;
    n->data = data;

    return status;
}

node *node_create(const void *data) {
    node *n = (node *) malloc(sizeof(node));
    if (n) {
        node_init(n, data);
    }

    return n;
}

int node_free(node *n) {
    int status = OK;

    if (n == NULL) {
        return status;
    }

    if (n->next) {
        node_free(n->next);
    }

    free(n);
    return status;
}