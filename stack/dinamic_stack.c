#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _STORE_TYPE
#include <stdint.h>
#endif /* _STORE_TYPE */

#include "dinamic_stack.h"

#ifndef _SIMPLE_NODE_DEFINED
#define _SIMPLE_NODE_DEFINED
struct node {
    void * restrict data;

#ifdef _STORE_TYPE
    char type;
#endif /* _STORE_TYPE */

    struct node * restrict next;
};
#endif // _end _SIMPLE_NODE_DEFINED

struct stack {
    struct node * restrict head;

#ifdef _STORE_ELEMENTS_NUM
    int32_t elements;
#endif /* _STORE_ELEMENTS_NUM */
};

struct stack * new_stack(void) {
    return (struct stack *) calloc(1, sizeof(struct stack));
}

#ifdef _STORE_TYPE

struct node * new_node(void * restrict data, const char type) {
    if( !data ) return NULL;

    struct node * new =
        (struct node *) calloc(1, sizeof(struct node));

    new->data = data;
    new->type = type;

    return new;
}

#else /* not defined _STORE_TYPE */

struct node * new_node(void * data) {

    if( !data ) return NULL;

    struct node * new = 
        (struct node *) calloc(1, sizeof(struct node));

    new->data = data;

    return new;
}

#endif /* end _STORE_TYPE */

bool push(struct stack  * restrict s, struct node * restrict n) {
    if( n ) {

        if( !stack_is_empty(s) ) n->next = s->head;

        s->head = n;

#ifdef _STORE_ELEMENTS_NUM
        s->elements++;
#endif // end _STORE_ELEMENTS_NUM

        return true;
    }

    return false;
}

struct node * pop(struct stack * restrict s) {
    struct node * tmp;

    tmp = s->head;

    if( stack_is_empty(s) ) {
         s->head = s->head->next;

#ifdef _STORE_ELEMENTS_NUM
         s->elements--;
#endif // end _STORE_ELEMENTS_NUM

         tmp->next = NULL;
    }

    return tmp;
}

void * stack_peek(const struct stack * restrict s) {
    return stack_is_empty(s) ? s->head->data : NULL;
}

bool stack_is_empty(const struct stack * restrict s) {
    return s->head == NULL;
}
