
#include "dinamic_queue.h"


struct queue * new_queue(void) {
    return (struct queue *) calloc(1, sizeof(struct queue));
}

#ifdef STORE_TYPE

struct node * new_node(void * restrict data, const char type) {
    if( !data ) return NULL;

    struct node * new =
        (struct node *) calloc(1, sizeof(struct node));

    new->data = data;
    new->type = type;

    return new;
}

#else /* not defined STORE_TYPE */

struct node * new_node(void * data) {

    if( !data ) return NULL;

    struct node * new = 
        (struct node *) calloc(1, sizeof(struct node));

    new->data = data;

    return new;
}

#endif /* end STORE_TYPE */

bool en_queue(struct queue  * restrict q, struct node * restrict n) {
    if( n ) {

        if( !queue_is_empty(q) ) q->rear->next = n;
        else                     q->head = n;

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

#ifdef STORE_ELEMENTS_NUM
         q->elements--;
#endif // STORE_ELEMENTS_NUM

         tmp->next = NULL;
    }

    return tmp;
}

bool queue_is_empty(const struct queue * restrict q) {
    return q->head == NULL;
}

void * queue_peek(const struct queue * restrict q) {
    return queue_is_empty(q) ? NULL : q->head;
}
