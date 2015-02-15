SOURCE = syspro.c Node_Type.c input_functions.c
OBJS = syspro.o Node_Type.o input_functions.o
HEADER = Node_Type.h input_functions.h
OUT = typing-assistant
CC = gcc
FLAGS = -g -c

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

syspro.o : syspro.c
	$(CC) $(FLAGS) syspro.c

Node_Type.o : Node_Type.c
	$(CC) $(FLAGS) Node_Type.c

input_functions.o : input_functions.c
	$(CC) $(FLAGS) input_functions.c

build : $(SOURCE)
	$(CC) -o $(OUT) $(SOURCE)

clean : 
	rm -f $(OBJS) $(OUT)

