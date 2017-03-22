#ifndef _DINAMIC_STACK_H
#define _DINAMIC_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef STORE_TYPE
#include <stdint.h>
#endif /* STORE_TYPE */

//#define STORE_TYPE
//#define STORE_ELEMENTS_NUM
//#define DOUBLE_LINKED

#ifndef _SIMPLE_NODE_DEFINED
#define _SIMPLE_NODE_DEFINED
struct node {
    void * restrict data;

#ifdef STORE_TYPE
    char type;
#endif /* end STORE_TYPE */

    struct node * restrict next;
#ifdef DOUBLE_LINKED
    struct node * restrict prev;
#endif /* end DOUBLE_LINKED */

};
#endif // end _SIMPLE_NODE_DEFINED

struct stack {
    struct node * restrict head;

#ifdef STORE_ELEMENTS_NUM
    int32_t elements;
#endif /* STORE_ELEMENTS_NUM */
};

/*-* Creating and deleting *-*/
extern struct stack * new_stack(void);
void free_stack(struct stack * restrict s);

#ifndef _NEW_NODE_DECLARED
#ifdef STORE_TYPE
struct node * new_node(void * restrict data, const char type);
#else
struct node * new_node(void * restrict data);
#endif // end STORE_TYPE
#endif /* _NEW_NODE_DECLARED */

/*-* Managing data *-*/
bool push(struct stack * restrict s, struct node * restrict n);
struct node * pop(struct stack * restrict s);
struct node * stack_peek(const struct stack * restrict s, bool from_start);

/*-* Extras *-*/
extern bool stack_is_empty(const struct stack * restrict s);

inline struct stack * new_stack(void) {
    return (struct stack *) calloc(1, sizeof(struct stack));
}

#ifdef STORE_TYPE
struct node * new_node(void * restrict data, const char type) {
#else /* not defined STORE_TYPE */
struct node * new_node(void * restrict data) {
#endif /* end STORE_TYPE */

    if( !data ) return NULL;

    struct node * new =
        (struct node *) calloc(1, sizeof(struct node));

    new->data = data;

#ifdef STORE_TYPE
    new->type = type;
#endif /* end STORE_TYPE */

    return new;
}


bool push(struct stack  * restrict s, struct node * restrict n) {
    if( n ) {

        if( !stack_is_empty(s) ) {
            n->next = s->head;
#ifdef DOUBLE_LINKED
        printf("Esta doblemente ligada\n");
            s->head->prev = n;
#endif /* DOUBLE_LINKED */
        }

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

    if( !stack_is_empty(s) ) {
         s->head = tmp->next;

#ifdef _STORE_ELEMENTS_NUM
         s->elements--;
#endif // end _STORE_ELEMENTS_NUM

#ifdef DOUBLE_LINKED
         if (tmp->next) tmp->next->prev = NULL;
#endif
         tmp->next = NULL;
    }

    return tmp;
}

struct node * stack_peek(const struct stack * restrict s, bool from_start) {
    static struct node * apt;

    if( from_start ) {
        apt = s->head;
    } else if( apt ) {
        apt = apt->next;
    }

    return apt;
}

inline bool stack_is_empty(const struct stack * restrict s) {
    return s->head == NULL;
}

#endif /* _DINAMIC_STACK_H */
