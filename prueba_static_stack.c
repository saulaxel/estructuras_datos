#include <stdio.h>
#define DOUBLE_LINKED
#include "./stack/static_stack.h"

void printStack(struct stack * s) {
    void * data = stack_peek(s, true);

    puts("El contenido de la pila es:");

    if( data ) {
        printf("| %9p | -> %2d\n", data, *((int *)data));
    }

    while( ( data = stack_peek(s, false) ) ) {
        printf("| %9p | -> %2d\n", data, *((int *)data));
    }

    puts("\n\n");
}

int main(void) {
    printf("Pruebas de la pila dinAmica:\n");
    int a[13] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 , 11, 12, 13};

    struct stack * pila = new_stack(10);

    push(pila, a + 0);
    printStack(pila);

    push(pila, (a + 1));
    printStack(pila);

    push(pila, (a + 2));
    printStack(pila);

    push(pila, (a + 3));
    printStack(pila);

    push(pila, (a + 4));
    printStack(pila);

    push(pila, (a + 5));
    printStack(pila);

    push(pila, (a + 6));
    printStack(pila);

    push(pila, (a + 7));
    printStack(pila);

    push(pila, (a + 8));
    printStack(pila);

    push(pila, (a + 9));
    printStack(pila);

    push(pila, (a + 10));
    printStack(pila);

    push(pila, (a + 11));
    printStack(pila);

    push(pila, (a + 12));
    printStack(pila);

    push(pila, (a + 13));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    push(pila, (a + 12));
    printStack(pila);

    (pop( pila ));
    printStack(pila);

    free_stack(pila);

    return 0;
}
