# No tengo la menor idea de como hacer un Makefile :S

# Compilador
CC = gcc
# Banderas
CFLAGS = -std=c11

prueba_stack: prueba_static_stack.c
	$(CC) -o prueba_stack prueba_stack.c $(CFLAGS)

prueba_stack: prueba_dinamic_stack.c
	$(CC) -o prueba_stack prueba_stack.c $(CFLAGS)

prueba_list: prueba_list.c
	$(CC) -o prueba_list list/list.c prueba_list.c $(CFLAGS)

prueba_queue: prueba_queue.c
	$(CC) -o prueba_queue queue/dinamic_queue.c prueba_queue.c $(CFLAGS)
