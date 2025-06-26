#include "tree.h"
#include "errors.h"

#include <stdio.h>

int int_cmp(const void *a, const void *b) {
    int diff = *((int *)a) - *((int *)b);
    if (diff > 0) {
        return 1;
    } else if (diff < 0) {
        return -1;
    } else {
        return 0;
    }
}


int main() {
    tree t;
    tree_init(&t);

    int a = 5;
    int b = 4;

    printf("size of tree is %lu\n", tree_size(&t));

    tree_insert(&t, (void *) &a, int_cmp);
    printf("size of tree is %lu\n", tree_size(&t));

    a = 6;
    
    tree_insert(&t, (void *) &a, int_cmp);
    printf("size of tree is %lu\n", tree_size(&t));

    a = 2;

    tree_insert(&t, (void *) &a, int_cmp);
    printf("size of tree is %lu\n", tree_size(&t));

    tree_free(&t);
    
    return 0;
}