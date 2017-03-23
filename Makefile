# No tengo la menor idea de como hacer un Makefile :S

# Compilador
CC = gcc
# Banderas
CFLAGS = -std=c11

prueba_stack.c:	ds
	$(CC) -o prueba_stack  stack/dinamic_stack.c prueba_stack.c $(CFLAGS)


prueba_list.c: dl
	$(CC) -o prueba_list list/list.c prueba_list.c $(CFLAGS)


prueba_queue.c: dq
	$(CC) -o prueba_queue queue/dinamic_queue.c prueba_queue.c $(CFLAGS)
