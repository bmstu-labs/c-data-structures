#pragma once

#include "node.h"

#include <unitypes.h>

typedef struct tree {
    node *root;
    size_t size;
} tree;

int tree_init(tree *t);

int tree_free(tree  *t);

int tree_insert(tree *t, const void *data, int (*cmp)(const void *, const void *));

int tree_to_array(tree *t, void **arr);

const node *tree_DFS(const tree *t, const void *data, int (*cmp)(const void *, const void *));

const node *tree_BFS(const tree *t, const void *data, int (*cmp)(const void *, const void *));

size_t tree_size(const tree *t);