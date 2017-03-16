#ifndef _STATIC_QUEUE
#define _STATIC_QUEUE

#include <stdbool.h>

#define _MAX_SIZE 10000

struct queue {
    void * * restrict content;
    int16_t max;
    int16_t head;
    int16_t rear;
};

struct queue * new_queue(int16_t size);
void free_queue(struct queue *);

bool en_queue(struct queue * q, void * data);
void * de_queue(struct queue * q);

bool queue_is_empty(const struct queue * q);
bool queue_is_full(const struct queue * q);

#endif /* _STATIC_queue */
