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
 * Library: static_stack
 * Description: A stack implementation with arrays in C.
 *#########################################################*/

#ifndef _STATIC_STACK
#define _STATIC_STACK

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

struct stack {
    void * restrict * content;
    int16_t top;
    int16_t max;
};

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function declarations -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/* Allocate and free memory*/
struct stack * new_stack(int16_t size);
static inline void free_stack(struct stack *);

/* Managing data */
void * pop(struct stack * s);
bool push(struct stack * s, void * data);
static inline void * stack_peek(const struct stack * s);

/* Auxiliar functions */
static inline bool stack_is_empty(const struct stack * s);
static inline bool stack_is_full(const struct stack * s);

/*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function definitions  -
 *-*-*-*-*-*-*-*-*-*-*-*-*/

/*
 * function   : new_stack
 * Description: Allocates memory for struct stack and
 *              a 'size' size array.
 *
 * Returns    : The direction of allocated memory if any or
 *              null otherwise.
 */
struct stack * new_stack(int16_t size) {

    if( size > _MAX_SIZE ) return NULL;

    struct stack * new =
        (struct stack*) malloc(sizeof(struct stack));

    if( !new ) return NULL;

    new->content =
        (void **) calloc(size , sizeof(void *));

    if( !new->content ) {
        free(new);
        return NULL;
    }

    new->max = size;
    new->top = -1;

    return new;
}

/*
 * Function   : free_stack
 * Description: Returns allocated memory of 's' to the system.
 */
static inline void free_stack(struct stack *s) {
    free(s->content);
    free(s);
}

/*
 * Function   : push
 * Description: Tries to push a generic data reference to 
 *              the top of the stack.
 *
 * Returns    : false if push is possible, true otherwise.
 */
bool push(struct stack * s, void * data) {
    if(!isFull(s)){
        s->top++;
        s->content[s->top] = data;
        return true;
    } else {
        return false;
    }
}

/*
 * Function   : pop
 * Description: Tries to pop the top of hte stack.
 *
 * Returns    : data if pop was possible, NULL otherwise.
 */
void * pop(struct stack * s) {
    void * temp;

    if (!isEmpty(s)) {
        temp = s->content[s->top];
        s->top--;
        return temp;
    } else {
        return NULL;
    }
}

/*
 * Function   : stack_is_empty
 * Description: Check if stack has no elements.
 *
 * Returns    : true if stack has no elements, false otherwise.
 */
static inline bool stack_is_empty(const struct stack * s){
    return s->top == -1;
}

/*
 * Function   : stack_is_full
 * Description: Check if stack has space.
 *
 * Returns    : true if stack has no space, false otherwise.
 */
static inline bool stack_is_full(const struct stack * s){
    return s->top == s->max -1;
}


/*
 * Function   : stack_peek
 * Description: returns the content of the stack one by one.
 *
 * returns    : First node if 'from_start' is true, secuentially
 *              calculated data when false.
 */
static inline void * stack_peek(const struct stack * s, int from_start) {
    static int i;

    if( from_start ) { i = s->top; }
    else             { --i;        }

    return (i > -1) ? s->content[i] : NULL;
}

#endif /* _STATIC_STACK */
