#ifndef ED_DEFINICIONES_H
#define ED_DEFINICIONES_H

#include <stdlib.h> // Reserva memoria
#include <string.h> // Para inicializar memoria
#include <assert.h> // Para propósitos de depuración
#include <stdint.h>

#define ASEGURARSE(condicion, mensaje) assert(((void)mensaje, condicion))
#define RESERVAR_ARR(tipo, cantidad) (tipo *) calloc(cantidad, sizeof(tipo))
#define REDIMENSIONAR_ARR(ref, tipo, cant_anterior, cant_nueva)     \
    do {                                                            \
        ref = (tipo *) realloc((void *)ref, cant_nueva * sizeof(tipo));\
        if ( ref != NULL && cant_nueva > cant_anterior ) {          \
            memset((void *)(ref + (cant_nueva - cant_anterior)), 0, \
                   (cant_nueva - cant_anterior) * sizeof(tipo));    \
        }                                                           \
    } while (0)

enum direccion_recorrido { HACIA_DELANTE, HACIA_ATRAS };

#endif /* ED_DEFINICIONES_H */
