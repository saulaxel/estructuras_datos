/*
 * (C) Copyright 2017 Martinez Ortiz Saul UNAM
 *
 * This program is free software: you can redistribute it and/or modify
 * Tt under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DINAMIC_QUEUE_H
#define _DINAMIC_QUEUE_H

/*-*-*-*-*-*-*-*-*
 -  Dependencies -
 *-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef STORE_TYPE
#include <stdint.h>
#endif /* STORE_TYPE */

/*-*-*-*-*-*-*-*-*-*-*
 - Data definitions  -
 *-*-*-*-*-*-*-*-*-*-*/
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

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function declarations -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/* Allocate and free memory*/
static inline struct queue * new_queue(void);
void freeQueue(struct queue * restrict q);

#ifdef STORE_TYPE
struct node * new_node(void * restrict data, const char type);
#else
struct node * new_node(void * restrict data);
#endif

/* Managing data */
bool en_queue(struct queue * restrict s, struct node * restrict n);
struct node * de_queue(struct queue * restrict s);
void * queue_peek(const struct queue * restrict q);

bool queue_is_empty(const struct queue * restrict q);

inline struct queue * new_queue(void) {
    return (struct queue *) calloc(1, sizeof(struct queue));
}

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function definitions  -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

#ifdef STORE_TYPE
struct node * new_node(void * restrict data, const char type) {
#else /* not defined STORE_TYPE */
struct node * new_node(void * data) {
#endif /* end STORE_TYPE */

    if( !data ) return NULL;

    struct node * nq =
        (struct node *) calloc(1, sizeof(struct node));

    nq->data = data;

#ifdef STORE_TYPE
    nq->type = type;
#endif /* end STORE_TYPE */

    return nq;
}

bool en_queue(struct queue  * restrict q, struct node * restrict n) {
    if( n ) {

        if( !queue_is_empty(q) ) {
            q->rear->next = n;

#ifdef DOUBLE_LINKED
            n->prev = q->rear;
#endif /*end DOUBLE_LINKED*/
        } else {
            q->head = n;
        }

        q->rear = n;

#ifdef STORE_ELEMENTS_NUM
        q->elements++;
#endif // end STORE_ELEMENTS_NUM

        return true;
    }

    return false;
}

struct node * de_queue(struct queue * restrict q) {
    struct node * tmp;

    tmp = q->head;

    if( !queue_is_empty(q) ) {
         q->head = q->head->next;
#ifdef DOUBLE_LINKED
         q->head->prev = NULL;
#endif /*end DOUBLE_LINKED*/

#ifdef STORE_ELEMENTS_NUM
         q->elements--;
#endif // STORE_ELEMENTS_NUM

         tmp->next = NULL;
#ifdef DOUBLE_LINKED
         tmp->prev = NULL;
#endif /*end DOUBLE_LINKED*/
    }

    return tmp;
}

inline bool queue_is_empty(const struct queue * restrict q) {
    return q->head == NULL;
}

void * queue_peek(const struct queue * restrict q) {
    return queue_is_empty(q) ? NULL : q->head;
}

#endif /* _OPERACIONES_PILA */

/*#########################################################
 * Library: static_queue
 * Description: A queue implementation with arrays in C.
 *#########################################################*/

#ifndef _STATIC_QUEUE
#define _STATIC_QUEUE

