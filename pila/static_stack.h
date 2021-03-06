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

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 -  Directivas preprocesador -
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define ASSERT_COND(condition, message) assert(((void)message, condition))
#define ALLOC_ARR(type, number) (type *) calloc(number, sizeof(type))
#define REALLOC_ARR(old, type, number) (type *) realloc(old, number * sizeof(type))

/*-*-*-*-*-*-*-*-*-*-*
 - Data definitions  -
 *-*-*-*-*-*-*-*-*-*-*/

struct stack {
    void * restrict * content;
    size_t top;
    size_t max;
};

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 - Function declarations and macrofunctions  -
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* Allocate and free memory*/
struct stack * new_stack(size_t size);
static inline void free_stack(struct stack *);

/* Managing data */
void * pop(struct stack * s);
bool push(struct stack * s, void * data);
static inline void * stack_peek(const struct stack * s,
        bool from_start);

/* Auxiliar functions */
static inline bool stack_is_empty(const struct stack * s);
static inline bool stack_is_full (const struct stack * s);

#endif /* PILA_H */
