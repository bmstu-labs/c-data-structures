#include "qnode.h"
#include "errors.h"

#include <stdlib.h>

int qnode_init(qnode *restrict n, const void *restrict data) {
    int status = OK;
    if (n == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    n->next = NULL;
    n->data = data;

    return status;
}

qnode *qnode_create(const void *data) {
    qnode *n = (qnode *) malloc(sizeof(qnode));
    if (n) {
        qnode_init(n, data);
    }

    return n;
}

int qnode_free(qnode *n) {
    int status = OK;

    if (n == NULL) {
        return status;
    }

    if (n->next) {
        qnode_free(n->next);
    }

    free(n);
    return status;
}