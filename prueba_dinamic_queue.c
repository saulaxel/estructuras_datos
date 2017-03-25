#include <stdio.h>
#define DOUBLE_LINKED
#include "./queue/dinamic_queue.h"

void printQueue(struct queue * q) {
    struct node * n = queue_peek(q, true);

    puts("El contenido de la cola es:");

    if( n ) {
        printf("| %9p | <- | %9p | -> | %9p |\n",
                n->prev, n, n->next);
    }

    while( (n = queue_peek(q, false)) ) {
        printf("| %9p | <- | %9p | -> | %9p |\n",
                n->prev, n, n->next);
    }

    puts("\n\n");
}

int main(void) {
    printf("Pruebas de la cola dinAmica:\n");
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    struct queue * cola = new_queue();

    en_queue(cola, new_node(a + 0));
    printQueue(cola);

    en_queue(cola, new_node(a + 1));
    printQueue(cola);

    en_queue(cola, new_node(a + 2));
    printQueue(cola);

    en_queue(cola, new_node(a + 3));
    printQueue(cola);

    en_queue(cola, new_node(a + 4));
    printQueue(cola);

    en_queue(cola, new_node(a + 5));
    printQueue(cola);

    en_queue(cola, new_node(a + 6));
    printQueue(cola);

    en_queue(cola, new_node(a + 7));
    printQueue(cola);

    en_queue(cola, new_node(a + 8));
    printQueue(cola);

    en_queue(cola, new_node(a + 9));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    en_queue(cola, new_node(a + 0));
    printQueue(cola);

    free(de_queue( cola ));
    printQueue(cola);

    free_queue(cola);

    return 0;
}
