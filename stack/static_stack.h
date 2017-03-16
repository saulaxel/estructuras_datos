#ifndef _STATIC_STACK
#define _STATIC_STACK

#define _MAX_SIZE 10000

struct stack {
    void ** content;
    int16_t top;
    int16_t max;
};

struct stack * newStack(int16_t size);
void freeStack(struct stack *);

void * pop(struct stack * s);
bool push(struct stack * s, void * data);
static int16_t getTop(const struct stack * s);
static bool isEmpty(const struct stack * s);
static bool isFull(const struct stack * s);
void * stackPeek(const struct stack * s);

#endif /* _STATIC_STACK */
