#pragma once

#include "qnode.h"

#include <unistd.h>

typedef struct queue {
    qnode *head;
    qnode *tail;
    size_t size;
} queue;

int queue_init(queue *q);

int queue_free(queue *q);

int queue_push(queue *q, const void *data);

void *queue_pop(queue *q);

size_t queue_size(const queue *q);

int queue_is_empty(const queue *q);

void *queue_peek(const queue *q);