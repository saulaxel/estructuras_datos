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

/*#########################################################
 * Library: static_queue
 * Description: A queue implementation with arrays in C.
 *#########################################################*/

#ifndef _STATIC_QUEUE
#define _STATIC_QUEUE

/*-*-*-*-*-*-*-*-*
 -  Dependencies -
 *-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*-*-*-*-*-*-*-*-*-*-*
 - Data definitions  -
 *-*-*-*-*-*-*-*-*-*-*/

#define _MAX_SIZE 10000

struct queue {
    /* Storage place */
    void * * restrict content;

    /* Limits */
    int16_t max;
    int16_t head;
    int16_t tail;

    /* State of the queue */
    bool is_empty;
    bool is_full;
};

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function declarations -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/* Allocate and free memory*/
struct queue * new_queue(int16_t size);
void          free_queue(struct queue * restrict q);

/* Managing data */
bool   en_queue(struct queue * restrict q, void * restrict data);
void * de_queue(struct queue * restrict q);
void * queue_pick(const struct queue * restrict q, bool from_start);

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function definitions  -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/*
 * function   : new_queue
 * Description: Allocates memory for struct queue and
 *              an 'size' elements array.
 *
 * Returns    : The direction of allocated memory if any or
 *              null otherwise.
 */
struct queue * new_queue(int16_t size) {

    if( size > _MAX_SIZE ) return NULL;

    struct queue * nq =
        (struct queue*) calloc(1, sizeof(struct queue));

    if( !nq ) return NULL;

    nq->content =
        (void **) calloc(size , sizeof(void *));

    if( !nq->content ) {
        free(nq);
        return NULL;
    }

    nq->max = size;
    nq->is_empty = true;

    return nq;
}

/*
 * Function    : free_queue
 * Description : Returns the space of the queue to the 
 *               system.
 */
void free_queue(struct queue * restrict q) {
    free(q->content);
    free(q);
}

/*
 * Function    : en_queue
 * Description : Insert an element in the start of the queue if 
 *               that queue is not full.
 *
 * Returns     : True if was able to insert, false if the 
 *               queue was full.
 */
bool en_queue(struct queue * restrict q, void * restrict data) {
    if( !q->is_full ){

        q->is_empty = false;

        q->content[q->tail] = data;
        q->tail = ( q->tail + 1 ) % q->max;

        if( q->head == q->tail ) { q->is_full = true; }

        return true;
    } else {
        return false;
    }
}

/*
 * Function    : de_queue
 * Description : Delete an element from the tail of the queue 
 *               if that queue is not empty.
 *
 * Returns     : True if was able to delete, false if the 
 *               queue was empty.
 */
void * de_queue(struct queue * restrict q) {
    void * temp;

    if (!q->is_empty) {

        q->is_full = false;

        temp = q->content[q->head];
        q->head = (q->head + 1) % q->max;

        if( q->head == q->tail ) { q->is_empty = true; }

        return temp;
    } else {
        return NULL;
    }
}

/*
 * Function    : queue_peek
 * Description : Returns data secuentially.
 *
 * Returns     : First element if 'from_start' is true the other
 *               if not.
 */
void * queue_peek(const struct queue * restrict q, bool from_start) {
    static int i;
    if(q->is_empty) return NULL;

    if( from_start ) {
        i = q->head;
    } else if( i == -1 ) {
        // Nothing
    } else if( (i + 1 ) % q->max  != q->tail ) {
        i = (i + 1) % q->max;
    } else {
        i = -1;
    }

    return (i != -1) ? q->content[i] : NULL;
}

#endif /* _STATIC_QUEUE */
