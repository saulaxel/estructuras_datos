#ifndef _PILA_ARREGLO
#define _PILA_ARREGLO

#define TAM_MAX 10000

struct pila {
    void ** stack;
    int16_t top;
    int16_t max;
};

struct pila * crearPila(int16_t tamanio);
void eliminarPila(struct pila *);
static int16_t numElemen(const struct pila * x);
static bool pilaVacia(const struct pila * x);
void * checarTope(const struct pila * s);
void * sacarDato(struct pila * s);
bool meterDato(struct pila * s, void * data);

#endif /* _PILA_ARREGLO */
