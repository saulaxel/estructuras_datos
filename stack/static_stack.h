#ifndef _STATIC_STACK
#define _STATIC_STACK

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define _MAX_SIZE 10000

struct stack {
    void * restrict * content;
    int16_t top;
    int16_t max;
};

struct stack * newStack(int16_t size);
static inline void freeStack(struct stack *);

void * pop(struct stack * s);
bool push(struct stack * s, void * data);
int16_t getTop(const struct stack * s);
static inline bool isEmpty(const struct stack * s);
static inline bool isFull(const struct stack * s);
static inline void * stackPeek(const struct stack * s);

struct stack * newStack(int16_t size) {

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

static inline void freeStack(struct stack *s) {
    free(s->content);
    free(s);
}

bool push(struct stack * s, void * data) {
    if(!isFull(s)){
        s->top++;
        s->content[s->top] = data;
        return true;
    } else {
        return false;
    }
}

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

static inline bool isEmpty(const struct stack * s){
    return s->top == -1;
}

static inline bool isFull(const struct stack * s){
    return s->top == s->max -1;
}

static inline void * stackPeek(const struct stack * s, int from_start) {
    static int i;

    if( from_start ) { i = s->top; }
    else             { --i;        }

    return (i > -1) ? s->content[i] : NULL;
}

#endif /* _STATIC_STACK */
