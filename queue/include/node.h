#pragma once

typedef struct node {
    void *data;
    struct node *next;
} node;

int node_init(node *n, const void *data);

node *node_create(const void *data);

int node_free(node *n);