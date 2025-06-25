#pragma once

#include "node.h"
#include <unitypes.h>

struct stack {
    struct node *top;
    size_t size;
};

int stack_init(struct stack *s);

int stack_free(struct stack *s);

struct node *stack_peek(const struct stack *s);

struct node *stack_pop(struct stack *s);

int stack_push(struct stack *s, const void *data);