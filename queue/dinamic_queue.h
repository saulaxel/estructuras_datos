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
    void * __restrict data;

#ifdef STORE_TYPE
    char type;
#endif /* STORE_TYPE */

    struct node * __restrict next;
#ifdef DOUBLE_LINKED
    struct node * __restrict prev;
#endif
};

#endif // _SIMPLE_NODE_DEFINED

struct queue {
    struct node * __restrict head;
    struct node * __restrict rear;

#ifdef STORE_ELEMENTS_NUM
    int16_t elements;
#endif /* STORE_ELEMENTS_NUM */
};

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function declarations -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/* Allocate and free memory*/
static inline struct queue * new_queue(void);
void freeQueue(struct queue * __restrict q);

#ifdef STORE_TYPE
struct node * new_node(void * __restrict data, const char type);
#else
struct node * new_node(void * __restrict data);
#endif

/* Managing data */
bool en_queue(struct queue * __restrict s, struct node * __restrict n);
struct node * de_queue(struct queue * __restrict s);
void * queue_peek(const struct queue * __restrict q, bool from_start);

bool queue_is_empty(const struct queue * __restrict q);

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function definitions  -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

static inline struct queue * new_queue(void) {
    return (struct queue *) calloc(1, sizeof(struct queue));
}

void free_queue(struct queue * __restrict q) {
    while( !queue_is_empty(q) )
        free(de_queue(q));

    free(q);
}

#ifdef STORE_TYPE
struct node * new_node(void * __restrict data, const char type) {
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

bool en_queue(struct queue  * __restrict q, struct node * __restrict n) {
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

struct node * de_queue(struct queue * __restrict q) {
    struct node * tmp;

    tmp = q->head;

    if( !queue_is_empty(q) ) {
         q->head = q->head->next;
#ifdef DOUBLE_LINKED
         if( q->head ) q->head->prev = NULL;
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

inline bool queue_is_empty(const struct queue * __restrict q) {
    return q->head == NULL;
}

void * queue_peek(const struct queue * __restrict q, bool from_start) {
    static struct node * apt;

    if( from_start ) { apt = q->head;   }
    else if( apt )   { apt = apt->next; }

    return apt;
}

#endif /* _DINAMIC_QUEUE_H */
