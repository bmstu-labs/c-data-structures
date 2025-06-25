#pragma once

struct node {
    void *data;
    struct node *next;
};

int node_init(struct node *n, const void *data);

int node_free(struct node *n);