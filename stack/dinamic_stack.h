#ifndef _OPERACIONES_PILA
#define _OPERACIONES_PILA

#define _STORE_TYPE
#define _STORE_ELEMENTS_NUM

/*-* Creating and deleting *-*/
struct stack * new_stack(void);
void free_stack(struct stack * restrict s);

#ifdef _STORE_TYPE
struct node * new_node(void * restrict data, const char type);
#else
struct node * new_node(void * restrict data);
#endif // end _STORE_TYPE


/*-* Managing data *-*/
bool push(struct stack * restrict s, struct node * restrict n);
struct node * pop(struct stack * restrict s);
void * stack_peek(const struct stack * restrict s);

/*-* Extras *-*/
bool stack_is_empty(const struct stack * restrict s);

#endif /* _OPERACIONES_PILA */
