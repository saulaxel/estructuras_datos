#ifndef _DINAMIC_QUEUE_H
#define _DINAMIC_QUEUE_H

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
#endif /* STORE_TYPE */

    struct node * restrict next;
#ifdef DOUBLE_LINKED
    struct node * restrict prev;
#endif
};

#endif // _SIMPLE_NODE_DEFINED

struct queue {
    struct node * head;
    struct node * rear;

#ifdef STORE_ELEMENTS_NUM
    int16_t elements;
#endif /* STORE_ELEMENTS_NUM */
};

inline struct queue * new_queue(void);
void freeQueue(struct queue * restrict q);

#ifdef STORE_TYPE
struct node * new_node(void * restrict data, const char type);
#else
struct node * new_node(void * restrict data);
#endif

bool en_queue(struct queue * restrict s, struct node * restrict n);
struct node * de_queue(struct queue * restrict s);
void * queue_peek(const struct queue * restrict q);

bool queue_is_empty(const struct queue * restrict q);

#endif /* _OPERACIONES_PILA */
