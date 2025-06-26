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
    if (t == NULL || t->root == NULL) {
        return NULL;
    }

    queue q;
    queue_init(&q);
    queue_push(&q, t->root);

    while (!queue_is_empty(&q)) {
        node *current = queue_pop(&q);
        if (cmp(current->data, data) == 0) {
            queue_free(&q);
            return current;
        }

        if (current->left) {
            queue_push(&q, current->left);
        }
        if (current->right) {
            queue_push(&q, current->right);
        }
    }

    queue_free(&q);
    return NULL;
}

static const node *dfs_recursive(const node *current, const void *data, int (*cmp)(const void *, const void *));

const node *tree_DFS(const tree *restrict t, const void *restrict data, int (*cmp)(const void *, const void *)) {
    if (t == NULL || t->root == NULL) {
        return NULL;
    }

    return dfs_recursive(t->root, data, cmp);
}

const node *dfs_recursive(const node *current, const void *data, int (*cmp)(const void *, const void *)) {
    if (current == NULL) {
        return NULL;
    }

    if (cmp(current->data, data) == 0) {
        return current;
    }

    const node *left_result = dfs_recursive(current->left, data, cmp);
    if (left_result != NULL) {
        return left_result;
    }

    return dfs_recursive(current->right, data, cmp);
}
