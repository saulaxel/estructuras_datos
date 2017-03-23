#include <stdio.h>
#define DOUBLE_LINKED
#include "./stack/dinamic_stack.h"

void printStack(struct stack * s) {
    struct node * n = stack_peek(s, true);

    puts("El contenido de la pila es:");

    if( n ) {
        printf("| %9p | <- | %9p | -> | %9p |\n",
                n->prev, n, n->next);
    }

    while( ( n = stack_peek(s, false) ) ) {
        printf("| %9p | <- | %9p | -> | %9p |\n",
                n->prev, n, n->next);
    }

    puts("\n\n");
}

int main(void) {
    printf("Pruebas de la pila dinAmica:\n");
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    struct stack * pila = new_stack();

    push(pila, new_node(a + 0));
    printStack(pila);

    push(pila, new_node(a + 1));
    printStack(pila);

    push(pila, new_node(a + 2));
    printStack(pila);

    push(pila, new_node(a + 3));
    printStack(pila);

    push(pila, new_node(a + 4));
    printStack(pila);

    push(pila, new_node(a + 5));
    printStack(pila);

    push(pila, new_node(a + 6));
    printStack(pila);

    push(pila, new_node(a + 7));
    printStack(pila);

    push(pila, new_node(a + 8));
    printStack(pila);

    push(pila, new_node(a + 9));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    push(pila, new_node(a + 0));
    printStack(pila);

    free(pop( pila ));
    printStack(pila);

    free_stack(pila);

    return 0;
}
