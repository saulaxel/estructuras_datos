#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef STORE_TYPE
#include <stdint.h>
#endif /* STORE_TYPE */

//#define STORE_TYPE
//#define STORE_ELEMENTS_NUM

struct list_node {
    void * restrict data;

#ifdef STORE_TYPE
    char type;
#endif /* STORE_TYPE */

    struct list_node * restrict next;

    struct list_node * restrict prev;

};

struct list {
    struct list_node * head;
    struct list_node * rear;

#ifdef STORE_ELEMENTS_NUM
    int16_t elements;
#endif /* STORE_ELEMENTS_NUM */
};

struct list * new_list(void);
void free_list(struct list * restrict l);

#ifdef STORE_TYPE
struct list_node * new_list_node(void * restrict data, const char type);
#else
struct list_node * new_list_node(void * restrict data);
#endif

bool insert_at(struct list * restrict l, struct list_node * restrict n, int index);
struct list_node * get_at(struct list * restrict l, int index);
void * list_peek_at(const struct list * restrict l);

bool list_is_empty(const struct list * restrict l);

#endif /* _LIST_H */
