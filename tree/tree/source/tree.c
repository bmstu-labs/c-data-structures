#include "tree.h"
#include "queue.h"
#include "errors.h"

#include <stdlib.h>

int tree_init(tree *t) {
    int status = OK;
    if (t == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    t->root = NULL;
    t->size = 0;

    return status;
}

int tree_free(tree *t)  {
    int status = OK;
    if (t ==  NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }
    node_free(t->root);
    t->root = NULL;
}

int tree_insert(tree *restrict t, const void *restrict data, int (*cmp)(const void *, const void *)) {
    int status = OK;
    if (t == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    node *n = node_create(data);
    if (n == NULL) {
        status = ALLOCATION_ERROR;
        return status;
    }

    node *current = t->root;
    node *parent = NULL;
    while (current) {
        parent = current;
        if (cmp(current->data, data) > 0) {
            current = current->right;
        }
        else {
            current = current->left;
        }
    }

    if (parent == NULL) {
        t->root = n;
    }
    else {
        if (cmp(parent->data, data) == 1) {
            parent->right = n;
        }
        else {
            parent->left = n;
        }
    }
    
    t->size++;
    return status;
}

size_t tree_size(const tree *t) {
    if (t == NULL) {
        return 0;
    }

    return t->size;
}

const node *tree_BFS(const tree *restrict t, const void *restrict data, int (*cmp)(const void *, const void *)) {
    return NULL;
}

const node *tree_DFS(const tree *restrict t, const void *restrict data, int (*cmp)(const void *, const void *)) {
    return NULL;
}