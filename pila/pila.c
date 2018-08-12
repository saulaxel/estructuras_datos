/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 -  Directivas preprocesador -
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
#include <stdbool.h>
#include "pila.h"
#include <definiciones.h>

#define TAM_INICIAL 8

/*-*-*-*-*-*-*-*-*-*-*-*
 - Definición de tipos -
 *-*-*-*-*-*-*-*-*-*-*-*/
struct pila {
    void * restrict * contenido;
    size_t cantidad;
    size_t tamanio;
};

struct recorredor {
    size_t indice;
    enum direccion_recorrido direccion;
};

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 - Declaraciones de funciones  -
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/* Creación y liberación de la pila*/
static struct pila * nueva_pila(void);
static inline void liberar_pila(struct pila *);

/* Manejar los datos */
static void * sacar_pila(struct pila * s);
static void insertar_pila(struct pila * s, void * data);
static void * checar_posicion_pila(struct pila * s, size_t posicion);
static inline void * recorrer_pila(const struct pila * s,
        bool from_start);

/* Funciones auxiliares */
static inline bool pila_vacia(const struct pila * s);
static inline bool pila_llena (const struct pila * s);

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
 - Definiciones de funciones -
 *-*-*-*-*-*-*-*-*-*-*-*-*-*-*/

/*
 * Función     : nueva_pila
 * Descripción : Reserva e inicializa los datos de una pila.
 *
 * Retorna     : La dirección de la pila creada.
 */
struct pila * nueva_pila(void) {
    struct pila * nueva = RESERVAR_ARR(struct pila, 1);
    ASEGURARSE(nueva != NULL, "Sin memoria para la pila\n");

    nueva->contenido = RESERVAR_ARR(void *, TAM_INICIAL);
    ASEGURARSE(nueva->contenido != NULL, "Sin memoria para el buffer de la pila\n");

    nueva->tamanio = TAM_INICIAL;
    return nueva;
}

/*
 * Función     : liberar_pila
 * Descripción : Libera el espacio para el contenido de la pila y para
 *               la pila en si.
 */
static inline void liberar_pila(struct pila * s) {
    free((void *)s->contenido);
    free(s);
}

/*
 * Función     : insertar_pila
 * Descripción : Inserta una referencia genérica en la pila. Puede
 *               causar que el buffer de la misma crezca.
 */
void insertar_pila(struct pila * s, void * data) {
    if (pila_llena(s)) {
        REDIMENSIONAR_ARR(s->contenido, void *, s->tamanio, s->tamanio * 2);
        ASEGURARSE(s->contenido != NULL, "Sin memoria para re-dimensionar");
        s->tamanio *= 2;
    }

    s->contenido[s->cantidad] = data;
    s->cantidad++;
}

/*
 * Función     : sacar_pila
 * Descripción : Elimina el último elemento ingresado y regresa su valor.
 *               Puede causar que el buffer de la pila decrezca.
 *
 * Regresa     : El dato sacado de la pila.
 */
static void * sacar_pila(struct pila * s) {
    void * temp;

    ASEGURARSE(!pila_vacia(s), "No hay elementos que sacar\n");

    if (s->tamanio > 64 && (s->cantidad) < (s->tamanio / 2)) {
        REDIMENSIONAR_ARR(s->contenido, void *, s->tamanio, s->tamanio / 2);
        s->tamanio /= 2;
    }

    s->cantidad--;
    temp = s->contenido[s->cantidad];
    return temp;
}

/*
 * Función     : pila_vacia
 * Regresa     : true si la pila esta vacia y false si no.
 */
static inline bool pila_vacia(const struct pila * s) {
    return s->cantidad == 0;
}

/*
 * Función    : pila_llena
 * Regresa    : true si el buffer se ha llenado y requiere re-dimensionado
 */
static inline bool pila_llena(const struct pila * s) {
    return s->cantidad == s->tamanio;
}

/*
 * Función    : checar_posicion_pila
 * Regresa    : El contenido de la pila en la posición especificada.
 */
static void * checar_posicion_pila(struct pila * s, size_t posicion) {
    ASEGURARSE(posicion <= s->tamanio, "El índice esta fuera de la posición");
    return s->contenido[posicion];
}

/*
 * Function   : recorrer_pila
 * Description: returns the contenido of the pila one by one.
 *
 * returns    : First data if 'from_start' is true, secuentially
 *              calculated data when false.
 */
static inline void * recorrer_pila(const struct pila * s,
        bool from_start) {
    static int i;

    if ( from_start ) { i = s->cantidad; }
    else              { --i;            }

    return (i > 0) ? s->contenido[i] : NULL;
}
