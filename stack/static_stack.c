#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "static_stack.h"

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

void freeStack(struct stack *s) {
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

static bool isEmpty(const struct stack * s){
    return s->top == -1;
}

static bool isFull(const struct stack * s){
    return s->top == s->max -1;
}

void * stackPeek(const struct stack * s) {
    return s->top != -1 ? s->content[s->top] : NULL;
}
