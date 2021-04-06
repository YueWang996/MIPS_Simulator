OBJS	= test.o utilities.o alu.o register.o instructionregister.o memory.o signextandbitshift.o controller.o
SOURCE	= test.cpp utilities.cpp alu.cpp register.cpp instructionregister.cpp memory.cpp signextandbitshift.cpp controller.cpp
HEADER	= utilities.h alu.h typedefine.h register.h instructionregister.h memory.h programcounter.h signextandbitshift.h controller.h
OUT	= test
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = -lboost_unit_test_framework

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

test.o: test.cpp
	$(CC) $(FLAGS) test.cpp 

utilities.o: utilities.cpp
	$(CC) $(FLAGS) utilities.cpp 

alu.o: alu.cpp
	$(CC) $(FLAGS) alu.cpp 

register.o: register.cpp
	$(CC) $(FLAGS) register.cpp 

instructionregister.o: instructionregister.cpp
	$(CC) $(FLAGS) instructionregister.cpp 

memory.o: memory.cpp
	$(CC) $(FLAGS) memory.cpp 

signextandbitshift.o: signextandbitshift.cpp
	$(CC) $(FLAGS) signextandbitshift.cpp 

controller.o: controller.cpp
	$(CC) $(FLAGS) controller.cpp 

clean:
	rm -f $(OBJS) $(OUT) log.txt