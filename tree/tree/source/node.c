#include "node.h"
#include "errors.h"

#include <stdlib.h>

int node_init(node *restrict n, const void *restrict data) {
    int status = OK;
    
    if (n == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    n->data = data;
    n->right = NULL;
    n->left = NULL;

    return status;
}

int node_free(node *n) {
    int status = OK;
    
    if (n == NULL) {
        return status;
    }

    if (n->left) {
        node_free(n->left);
    }
    if (n->right) {
        node_free(n->right);
    }

    free(n);

    return status;
}

node *node_create(const void *data) {
    node *n = (node *) malloc(sizeof(node));
    
    if (n != NULL) {
        node_init(n, data);
    }

    return n;
}