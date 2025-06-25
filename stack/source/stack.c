#include "stack.h"
#include "errors.h"

#include <stdlib.h>

int stack_init(struct stack *s) {
    int status = OK;

    if (s == NULL) {
        status = NULLPTR_GIVEN;
    }
    
    s->top = NULL;
    s->size = 0;

    return status;
}

int stack_free(struct stack *s) {
    int status = OK;

    if (s == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    node_free(s->top);

    s->top = NULL;
    s->size = 0;

    return status;
}

struct node *stack_peek(const struct stack *s) {
    if (s == NULL) {
        return NULL;
    }

    return s->top;
}

struct node *stack_pop(struct stack *s) {
    struct node *result = NULL;
    if (s == NULL) {
        return result;
    }

    result = s->top;
    if (s->top != NULL) {
        s->top = result->next;
        result->next = NULL;
        s->size--;
    }
    
    return result;
}

int stack_push(struct stack *restrict s, const void *restrict data) {
    int status = OK;
    if (s == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    struct node *n = (struct node *) malloc(sizeof(struct node));
    if (n == NULL) {
        status = ALLOCATION_ERROR;
        return status;
    }

    node_init(n, data);

    n->next = s->top;
    s->top = n;
    s->size++;

    return status;
}