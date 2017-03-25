#include <stdio.h>
#define STORE_ELEMENTS_NUM
#include "./list/list.h"

#define my_insert insert_as_first
#define my_delete remove_first

void printList(struct list * l) {
    struct list_node * n = list_peek(l, true);

    printf("El contenido %d de la lista es:\n", l->elements);

    if( n ) {
        printf("| %9p | <- | %9p | -> | %9p |\n",
                n->prev, n, n->next);
    }

    while( ( n = list_peek(l, false) ) ) {
        printf("| %9p | <- | %9p | -> | %9p |\n",
                n->prev, n, n->next);
    }

    puts("\n\n");
}

int main(void) {
    printf("Pruebas de la lista dinAmica:\n");
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    struct list * lista = new_list();

    my_insert(lista, new_list_node(a + 0));
    getchar();
    printList(lista);


    my_insert(lista, new_list_node(a + 1));
    printList(lista);

    my_insert(lista, new_list_node(a + 2));
    printList(lista);

    my_insert(lista, new_list_node(a + 3));
    printList(lista);

    my_insert(lista, new_list_node(a + 4));
    printList(lista);

    my_insert(lista, new_list_node(a + 5));
    printList(lista);

    my_insert(lista, new_list_node(a + 6));
    printList(lista);

    my_insert(lista, new_list_node(a + 7));
    printList(lista);

    my_insert(lista, new_list_node(a + 8));
    printList(lista);

    my_insert(lista, new_list_node(a + 9));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    my_insert(lista, new_list_node(a + 0));
    printList(lista);

    free(my_delete( lista ));
    printList(lista);

    free_list(lista);

    return 0;
}
