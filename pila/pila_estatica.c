#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "pila_arreglo.h"

struct pila * crearPila(int16_t tamanio) {

    if( tamanio > TAM_MAX ) return NULL;

    struct pila * nueva_pila = 
        (struct pila*) malloc(sizeof(struct pila));

    if( !nueva_pila ) return NULL;

    nueva_pila->stack = 
        (void **) calloc(tamanio, sizeof(void *));

    if( !nueva_pila->stack ) {
        free(nueva_pila);
        return NULL;
    }

    nueva_pila->max = tamanio;
    nueva_pila->top = -1;

    return nueva_pila;
}

static int16_t numElemen(const struct pila * s) {
    return s->top + 1;
}

static bool pilaVacia(const struct pila * s){
    if(numElemen(s) == 0)
        return true;
    return false;
}

static bool pilaLlena(const struct pila * s){
    if(numElemen(s) == s->max)
        return true;
    return false;
}

void * checarTope(const struct pila * s) {
    return s->stack[s->top];
}

void * sacarDato(struct pila * s) {
    void * temp;
    if (!pilaVacia(s)) {
        temp = s->stack[s->top];
        s->top--;
        return temp;
    } else {
        return NULL;
    }
}

bool meterDato(struct pila * s, void * data) {
    if(!pilaLlena(s)){
        s->top++;
        (s->stack)[s->top] = data;
        return true;
    } else {
        return false;
    }
}

