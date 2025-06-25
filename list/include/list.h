#pragma once

#include "node.h"

#include <unitypes.h>

struct list {
    struct node *head;
    size_t size;
};

int list_init(struct list *l);

int list_push_back(struct list *l, struct node *n);

int list_push_front(struct list *l, struct node *n);

struct node *list_get(struct list *l, size_t index);

struct node *list_head(struct list *l);

struct node *list_tail(struct list *l);

int list_empty(const struct list *l);

int list_free(struct list *l);