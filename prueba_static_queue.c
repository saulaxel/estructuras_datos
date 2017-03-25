#include <stdio.h>
#define DOUBLE_LINKED
#include "./queue/static_queue.h"

void printStack(struct queue * restrict s) {
    void * data = queue_peek(s, true);

    puts("El contenido de la cola es:");

    if( data ) {
        printf("| %9p | -> %2d\n", data, *((int *)data));
    }

    while( ( data = queue_peek(s, false) ) ) {
        printf("| %9p | -> %2d\n", data, *((int *)data));
    }

    puts("\n\n");
}

int main(void) {
    printf("Pruebas de la cola dinAmica:\n");
    int a[14] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13, 14 };

    struct queue * pila = new_queue(10);

    en_queue(pila, a + 0);
    printStack(pila);

    en_queue(pila, (a + 1));
    printStack(pila);

    en_queue(pila, (a + 2));
    printStack(pila);

    en_queue(pila, (a + 3));
    printStack(pila);

    en_queue(pila, (a + 4));
    printStack(pila);

    en_queue(pila, (a + 5));
    printStack(pila);

    en_queue(pila, (a + 6));
    printStack(pila);

    en_queue(pila, (a + 7));
    printStack(pila);

    en_queue(pila, (a + 8));
    printStack(pila);

    en_queue(pila, (a + 9));
    printStack(pila);

    en_queue(pila, (a + 10));
    printStack(pila);

    en_queue(pila, (a + 11));
    printStack(pila);

    en_queue(pila, (a + 12));
    printStack(pila);

    en_queue(pila, (a + 13));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    en_queue(pila, (a + 12));
    printStack(pila);

    en_queue(pila, (a + 13));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    en_queue(pila, (a + 12));
    printStack(pila);

    (de_queue( pila ));
    printStack(pila);

    free_queue(pila);

    return 0;
}
