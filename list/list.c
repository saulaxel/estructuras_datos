
#include "list.h"

struct list * new_list(void) {
    return (struct list *) calloc(1, sizeof(struct list));
}

#ifdef STORE_TYPE

struct list_node * new_node(void * restrict data, const char type) {
    if( !data ) return NULL;

    struct list_node * new =
        (struct list_node *) calloc(1, sizeof(struct list_node));

    new->data = data;
    new->type = type;

    return new;
}

#else /* not defined STORE_TYPE */

struct list_node * new_list_node(void * data) {

    if( !data ) return NULL;

    struct list_node * new = 
        (struct list_node *) calloc(1, sizeof(struct list_node));

    new->data = data;

    return new;
}

#endif /* end STORE_TYPE */

bool insert_at(struct list  * restrict l, struct list_node * restrict n, int index) {
    struct list_node * aux;
    int i = 1;

    if( !n ) return false;


    if( list_is_empty(l) ) {
        l->head = l->rear = n;

        n->next = n;
        n->prev = n;

    } else {
        aux = l->head;

        if ( index > 0 ) {
            aux = l->head;

            while( i < index && aux != l->rear ) {
                aux = aux->next;
            }

            if( l->head == l->rear ) {
                aux->next = n;
                aux->prev = n;

                n->next = aux;
                n->prev = aux;

                l->rear = n;
            } else if( aux == l->rear ) {
                aux->next = n;

                n->next = l->head;
                n->prev = aux;

                l->rear = n;
            } else {
                n->next = aux->next;
                n->prev = aux;
                aux->next = n;
            }

        } else {
            index = -index + 1;

            while( i <= index && aux != l->head->next ) {
                aux = aux->prev;
            }

            if( l->head == l->rear ) {
                aux->prev = n;
                aux->next = n;

                n->prev = aux;
                n->next = aux;

                l->head = n;
            } else if( aux == l->head ){
                aux->prev = n;

                n->prev = l->rear;
                n->next = aux;

                l->head = n;
            } else {
                n->prev = aux->prev;
                n->next = aux;
                aux->prev = n;
            }

        }
    }

#ifdef STORE_ELEMENTS_NUM
    q->elements++;
#endif // end STORE_ELEMENTS_NUM

    return true;
}

struct list_node * get_at(struct list * restrict l, int index) {
    struct list_node * tmp;
    int i = 0;

    tmp = l->head;

    if( !list_is_empty(l) ) {
        if( tmp == l->rear ) {
            l->head = l->rear = NULL;

            tmp->next = tmp->prev = NULL;

#ifdef STORE_ELEMENTS_NUM
            elements = 0;
#endif // end STORE_ELEMENTS_NUM
            return tmp;
        }

        if( index >= 0 ) {
            while( i < index && tmp != l->rear ) {
                tmp = tmp->next;
            }

            tmp->prev->next = tmp->next;
            tmp->next->prev = tmp->prev;

            if      ( tmp == l->head ) l->head = tmp->next;
            else if ( tmp == l->rear ) l->rear = tmp->prev;

        } else {
            index = -index + 1;

            while( i < index && tmp != l->head->next ) {
                tmp = tmp->prev;
            }

            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;

            if      ( tmp == l->rear ) l->rear = tmp->prev;
            else if ( tmp == l->head ) l->head = tmp->next;

        }

    }

#ifdef STORE_ELEMENTS_NUM
    tmp->next = tmp->prev = NULL;
    q->elements--;
#endif // end STORE_ELEMENTS_NUM

    return tmp;
}

bool list_is_empty(const struct list * restrict l) {
    return l->head == NULL;
}

void * list_peek(const struct list * restrict l) {
    return list_is_empty(l) ? NULL : l->head;
}
