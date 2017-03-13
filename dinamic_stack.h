#ifndef _OPERACIONES_PILA
#define _OPERACIONES_PILA

#define _STORE_TYPE
#define _STORE_ELEMENTS_NUM

struct stack * newStack(void);
void freeStack(struct stack * restrict s);

#ifdef _STORE_TYPE
struct node * newNode(void * restrict data, const char type);
#else
struct node * newNode(void * restrict data);
#endif

bool push(struct stack * restrict s, struct node * restrict n);
struct node * pop(struct stack * restrict s);
void * peek(const struct stack * restrict s);

static bool isNotEmpty(const struct stack * restrict s);

#endif /* _OPERACIONES_PILA */
