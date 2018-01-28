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
 * Library: list
 * Description: A list implementation with structs in C.
 *#########################################################*/

#ifndef _LIST_H
#define _LIST_H

/*-*-*-*-*-*-*-*-*
 -  Dependencies -
 *-*-*-*-*-*-*-*-*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#ifdef STORE_TYPE
#include <stdint.h>
#endif /* STORE_TYPE */

/*-*-*-*-*-*-*-*-*-*-*
 - Data definitions  -
 *-*-*-*-*-*-*-*-*-*-*/

//#define STORE_TYPE
//#define STORE_ELEMENTS_NUM

struct list_node {
    void * __restrict data;

#ifdef STORE_TYPE
    char type;
#endif /* STORE_TYPE */

    struct list_node * __restrict next;

    struct list_node * __restrict prev;

};

struct list {
    struct list_node * __restrict head;
    struct list_node * __restrict rear;

#ifdef STORE_ELEMENTS_NUM
    int32_t elements;
#endif /* STORE_ELEMENTS_NUM */
};


/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function declarations -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/* Allocate and free memory*/
extern struct list * new_list(void);
void free_list(struct list * __restrict l);

#ifdef STORE_TYPE
struct list_node * new_list_node(void * __restrict data, const char type);
#else
struct list_node * new_list_node(void * __restrict data);
#endif

/* Managing data */
bool insert_at(struct list * __restrict l,
        struct list_node * __restrict n, int index);
extern inline bool insert_as_first(struct list * __restrict l,
        struct list_node * __restrict n);
extern inline bool insert_as_last (struct list * __restrict l,
        struct list_node * __restrict n);

struct list_node * remove_at(struct list * __restrict l, int index);
extern inline struct list_node * remove_first(struct list * __restrict l);
extern inline struct list_node * remove_last (struct list * __restrict l);

void * list_peek_at(const struct list * __restrict l);

/* Auxiliar functions */
bool list_is_empty(const struct list * __restrict l);

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function definitions  -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/*
 * Function    : new_list
 * Description : Allocates memory for a struct list.
 *
 * Returns     : Adress of the allocated memory.
 */
inline struct list * new_list(void) {
    return (struct list *) calloc(1, sizeof(struct list));
}

/*
 * Function    : free_list
 * Description : Returns the memory of a list and its nodes to
 *               the system.
 */
void free_list(struct list * __restrict l) {
    while( !list_is_empty(l) ) {
        free(remove_last(l));
    }

    free(l);
}

/*
 * Function    : new_node
 * Description : Looks for memory for a struct list_node and allocates 
 *               the space if possible.
 *
 * Returns     : Adress of the memory.
 */
#ifdef STORE_TYPE
struct list_node * new_node(void * __restrict data, const char type) {
#else /* not defined STORE_TYPE */
struct list_node * new_list_node(void * data) {
#endif /* end STORE_TYPE */

    if( !data ) return NULL;

    struct list_node * nl =
        (struct list_node *) calloc(1, sizeof(struct list_node));

    nl->data = data;

#ifdef STORE_TYPE
    nl->type = type;
#endif /* STORE_TYPE */

    return nl;
}

/*
 * Function    : insert_at
 * Description : Insert a list_node in the 'index' position, 0 inserts at
 *               at first, 1 inserts between 1st and 2nd etc...
 *               The integer can be negative no count backwards, so -1 would
 *               insert at last position, -2 between last and the previous 
 *               to it etc..
 *
 * Returns     : False if not receiving a valid node, true otherwise.
 */
bool insert_at(struct list  * __restrict l, struct list_node * __restrict n, int32_t index) {
    struct list_node * aux = l->head;
    int32_t i = 0;

    if( !n ) return false;

#ifdef STORE_ELEMENTS_NUM
    l->elements++;
#endif // end STORE_ELEMENTS_NUM

    if( list_is_empty(l) ) {
        l->head = l->rear = n;

        n->next = n->prev = n;

        return true;
    }

#ifdef STORE_ELEMENTS_NUM
    if( index > l->elements )         index = -1;
    else
    if( index < -(l->elements + 1))   index =  0;
#endif

    if( index > 0 ) {
        while( ++i < index && aux->next != l->head ) aux = aux->next;
        index = i;
    } else {

        index = -index;
        aux = aux->prev;
        while( ++i < index && aux->prev != l->head ) aux = aux->prev;

        if( index > 0 ) index = -i;
    }

    if( l->head == l->rear ) {
        aux->next = n;
        aux->prev = n;

        n->next = aux;
        n->prev = aux;

        if( index ) l->rear = n;
        else        l->head = n; 

    } else if( aux == l->rear ) {
        aux->next = n;
        n->prev = aux;

        n->next = l->head;
        l->head->prev = n;

        if( index ) l->rear = n;
        else        l->head = n;
    } else {
        n->next = aux->next;
        n->prev = aux;

        aux->next->prev = n;
        aux->next = n;
    }

    return true;
}

/*
 * Function    : insert_as_first
 * Description : Calls insert_at with index 0 for always insert at first.
 * 
 * Returns     : Result of insert_at.
 */
inline bool insert_as_first(struct list * __restrict l,
                                        struct list_node * __restrict n) {
    return insert_at(l, n, 0);
}

/*
 * Function    : insert_as_last
 * Description : Calls insert_at with index -1 for always insert at last.
 *
 * Returns     : Result of insert_at.
 */
inline bool insert_as_last(struct list * __restrict l,
                                        struct list_node * __restrict n) {
    return insert_at(l, n, -1);
}

/*
 * Function    : remove_at
 * Description : Take the 'index'th node out of the list. 1 is the first
 *               node, (actually also 0), 2 the second, It's possible
 *               to specify a negative number to walk through the list
 *               backward.
 *
 * Returns     : Adress of the node.
 */
struct list_node * remove_at(struct list * __restrict l, int32_t index) {
    struct list_node * tmp;
    int32_t i = 0;

    if( list_is_empty(l) ) return NULL;

#ifdef STORE_ELEMENTS_NUM
    l->elements--;
#endif /* STORE_ELEMENTS_NUM */

    tmp = l->head;

#ifdef STORE_ELEMENTS_NUM
    if( index > l->elements )         index = -1;
    else
    if( index < -(l->elements + 1))   index =  0;
#endif

    if( index >= 0 ) {
        while( ++i <= index && tmp->next != l->head ) tmp = tmp->next;
    } else {
        index = -index;
        while( ++i <= index && tmp->prev != l->head ) tmp = tmp->prev;
    }

    if( l->head == l->rear ) {
        l->head = l->rear = NULL;

    } else if( tmp == l->head ) {
        l->head = tmp->next;

        l->head->prev = l->rear;
        l->rear->next = l->head;
    } else if( tmp == l->rear ) {
        l->rear = tmp->prev;

        l->rear->next = l->head;
        l->head->prev = l->rear;
    } else {
        tmp->prev->next = tmp->next;
        tmp->next->prev = tmp->prev;
    }

    tmp->next = tmp->prev = NULL;
    return tmp;
}

/*
 * Function    : remove_first
 * Description : Calls 'remove_at' with index 0 to remove first.
 *
 * Returns     : Result of 'remove_at'.
 */
inline struct list_node * remove_first(struct list * __restrict l) {
    return remove_at(l, 0);
}

/*
 * Function    : remove_first
 * Description : Calls 'remove_at' with index -1 to remove last.
 *
 * Returns     : Result of 'remove_at'.
 */
inline struct list_node * remove_last(struct list * __restrict l) {
    return remove_at(l, -1);
}

/*
 * Function    : list_is_empty
 * Description : Tells the program if the list is empty.
 *
 * Returns     : True is so, false otherwise.
 */
bool list_is_empty(const struct list * __restrict l) {
    return l->head == NULL;
}

/*
 * Function    : list_peek
 * Description : Returns the content of the list one by one untill its
 *               over. You have to use a true value for 'from_start'
 *               first time or always you want to refresh the list
 *               to the start.
 *
 * Returns     : Adress of the corresponding node.
 */
void * list_peek(const struct list * __restrict l, bool from_start) {
    static struct list_node * tmp = NULL;

    if( from_start ) {
        tmp = l->head;
    } else if( tmp ){
        if( tmp->next == l->head ) {
            tmp = NULL;
        } else {
            tmp = tmp->next;
        }
    }

    return tmp;
}

#endif /* _LIST_H */
