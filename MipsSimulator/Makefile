OBJS	= main.o register.o utilities.o memory.o alu.o signextandbitshift.o instructionregister.o controller.o
SOURCE	= main.cpp register.cpp utilities.cpp memory.cpp alu.cpp signextandbitshift.cpp instructionregister.cpp controller.cpp
HEADER	= register.h utilities.h programcounter.h memory.h alu.h typedefine.h signextandbitshift.h instructionregister.h controller.h
OUT	= MipsSimulator
CC	 = g++
FLAGS	 = -g -c -Wall
LFLAGS	 = 


all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp 

register.o: register.cpp
	$(CC) $(FLAGS) register.cpp 

utilities.o: utilities.cpp
	$(CC) $(FLAGS) utilities.cpp 

memory.o: memory.cpp
	$(CC) $(FLAGS) memory.cpp 

alu.o: alu.cpp
	$(CC) $(FLAGS) alu.cpp 

signextandbitshift.o: signextandbitshift.cpp
	$(CC) $(FLAGS) signextandbitshift.cpp 

instructionregister.o: instructionregister.cpp
	$(CC) $(FLAGS) instructionregister.cpp 

controller.o: controller.cpp
	$(CC) $(FLAGS) controller.cpp 

clean:
	rm -f $(OBJS) $(OUT) log.txt