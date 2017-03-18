#include <stdio.h>
#include <stdint.h>
#include "./queue/static_queue.h"

void printQueue(struct queue * q) {
    puts("The queue is: ");

    if( q->head != -1 ) {
        for(int i = q->head; i <= q->rear; ++i) {
            printf("%p -> %d\n", q->content[i], *((int *)q->content[i]));
        }
    }

    puts("\n");
}

int32_t main(void) {
    struct queue * cola = new_queue(10);

    int x = 10, y = 11, z = 14, w = 9, v = 7;

    int b, c, d, e, f, g;

    en_queue(cola, &x) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &y) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &z) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &w) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &d) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &c) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &b) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &f) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &g) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &e) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &v) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);

    en_queue(cola, &z) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    en_queue(cola, &y) ? printf("Se pudo encolar\n") : printf("No se pudo encolar\n");
    printQueue(cola);

    de_queue(cola) ? printf("Se pudo desencolar\n"): printf("No se pudo desencolar\n");
    printQueue(cola);
    return 0;
}
