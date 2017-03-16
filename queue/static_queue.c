#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "static_queue.h"

struct queue * new_queue(int16_t size) {

    if( size > _MAX_SIZE ) return NULL;

    struct queue * new =
        (struct queue*) malloc(sizeof(struct queue));

    if( !new ) return NULL;

    new->content =
        (void **) calloc(size , sizeof(void *));

    if( !new->content ) {
        free(new);
        return NULL;
    }

    new->max = size;
    new->head = -1;
    new->rear = -1;

    return new;
}

void free_queue(struct queue * q) {
    free(q->content);
    free(q);
}

bool en_queue(struct queue * q, void * data) {
    if(!queue_is_full(q)){

        if( queue_is_empty(q) ) q->head = 0;

        q->rear++;
        q->content[q->rear] = data;
        return true;
    } else {
        return false;
    }
}

void * de_queue(struct queue * q) {
    void * temp;

    if (!queue_is_empty(q)) {
        temp = q->content[q->head];
        q->head++;

        if( q->head > q->rear ) {
            q->head = q->rear = -1;
        }

        return temp;
    } else {
        return NULL;
    }
}

bool queue_is_empty(const struct queue * q) {
    return q->head == -1;
}

bool queue_is_full(const struct queue * q) {
    return q->rear == q->max -1;
}

void * peek(const struct queue * q) {
    return queue_is_empty(q) ? NULL : q->content[q->head];
}
