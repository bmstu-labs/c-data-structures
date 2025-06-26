#pragma once

typedef struct node {
    void *data;
    struct node *right;
    struct node *left;
} node;

int node_init(node *n, const void *data);

int node_free(node *n);

node *node_create(const void *data);