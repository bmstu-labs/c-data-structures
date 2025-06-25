#pragma once

#include "node.h"

#include <unitypes.h>

struct list {
    struct node *head;
    size_t size;
};

int list_init(struct list *l);

int list_push_back(struct list *l, void *n);

int list_push_front(struct list *l, void *n);

void *list_get(struct list *l, size_t index);

void *list_head(struct list *l);

void *list_tail(struct list *l);

int list_empty(const struct list *l);

int list_free(struct list *l);