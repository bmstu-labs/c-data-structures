#pragma once

typedef struct qnode {
    void *data;
    struct qnode *next;
} qnode;

int qnode_init(qnode *n, const void *data);

qnode *qnode_create(const void *data);

int qnode_free(qnode *n);