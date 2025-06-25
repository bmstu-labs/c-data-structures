#include "list.h"
#include "errors.h"

#include <stdlib.h>

int list_init(struct list *l) {
    int status = OK;

    if (l == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    l->head = NULL;
    l->size = 0;

    return status;
}

int list_push_back(struct list *restrict l, void *restrict data) {
    int status = OK;
    if (l == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    // Allocate and init node
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if (n == NULL) {
        status = ALLOCATION_ERROR;
        return status;
    }

    node_init(n, data);
    
    if (l->head == NULL) {
        l->head = n;
    }
    else {
        // Iterate to last element
        struct node *current = l->head;
        while (current->next) {
            current = current->next;
        }

        // Set last element
        current->next = n;
    }

    // Increment size
    l->size++;

    if (n->next) {
        status = NEXT_NODE_NOT_EMPTY;
    }

    return status;
}

int list_push_front(struct list *restrict l, void *restrict data) {
    int status = OK;
    if (l == NULL) {
        status = NULLPTR_GIVEN;
        return status;
    }

    // Allocate and init node
    struct node *n = (struct node *) malloc(sizeof(struct node));
    if (n == NULL) {
        status = ALLOCATION_ERROR;
        return status;
    }

    node_init(n, data);

    // If the list has no elements
    if (l->head == NULL) {
        l->head = n;
    }
    else {
        // Set first element
        n->next = l->head;
        l->head = n;
    }

    // Increment size
    l->size++;

    return status;
}

void *list_get(struct list *l, size_t index) {
    struct node *result = NULL;
    if (l == NULL) {
        return result;
    }

    size_t counter = 0;
    struct node *current = l->head;
    while (current) {
        if (index == counter) {
            result = current;
            break;
        }
        current = current->next;
        counter++;
    }

    return result->data;
}

void *list_head(struct list *l) {
    return (l == NULL) ? NULL : l->head->data;
}

void *list_tail(struct list *l) {
    struct node *result = NULL;
    if (l == NULL || list_empty(l) == TRUE) {
        return result;
    }

    struct node *current = l->head;
    while (current->next) {
        current = current->next;
    }

    result = current;

    return result->data;
}

int list_empty(const struct list *l) {
    return (l->head == NULL) ? TRUE : FALSE;
}

int list_free(struct list *l) {
    int status = OK;
    if (l == NULL) {
        status = NULLPTR_GIVEN;
        return  status;
    }

    if (list_empty(l) == TRUE) {
        status = LIST_IS_EMPTY;
        return status;
    }

    status = node_free(l->head);
    
    l->head = NULL;
    l->size = 0;

    return status;
}
