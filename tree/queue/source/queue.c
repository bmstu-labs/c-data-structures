#include "queue.h"
#include "errors.h"

#include <stdlib.h>

int queue_init(queue *q) {
    int status = OK;
    if (q == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    q->head = NULL;
    q->tail = NULL;
    q->size = 0;

    return status;
}

int queue_free(queue *q) {
    int status = OK;
    if (q == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    status = qnode_free(q->tail);
    if (status == OK) {
        q->head = NULL;
        q->tail = NULL;
        q->size = 0;
    }

    return status;
}

int queue_push(queue *restrict q, const void *restrict data) {
    int status = OK;
    if (q == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    qnode *n = qnode_create(data);
    if (n == NULL) {
        status = ALLOCATION_ERROR;
        return status;
    }

    if (q->head == NULL) {
        q->head = n;
    }

    n->next = q->tail;
    q->tail = n;
    q->size++;

    return status;
}

void *queue_pop(queue *q) {
    void *result = queue_peek(q);

    if (q->head == NULL) {
        return result;
    }

    qnode *current = q->tail;
    while (current->next != NULL && current->next != q->head) {
        current = current->next;
    }
    
    if (current == q->head) {
        free(current);
        q->head = NULL;
        q->tail = NULL;
    }
    else {
        free(q->head);
        q->head = current;
        q->head->next = NULL;
    }
    
    q->size--;
    return result;
}

void *queue_peek(const queue *q) {
    if (q == NULL || q->head == NULL) {
        return NULL;
    }

    return q->head->data;
}

size_t queue_size(const queue *q) {
    size_t size = 0;
    if (q != NULL) {
        size = q->size;
    }

    return size;
}

int queue_is_empty(const queue *q) {
    if (q == NULL) {
        return TRUE;
    }

    return (q->size == 0) ? TRUE : FALSE;
}