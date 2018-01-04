
EXE = 2-6.exe
OBJ = 2-6.o
BOOSTLIBS    =   $(shell forBoost)
OPENCVLIBS   =   $(shell forOpenCV)

BOOSTINCDIR = -I$(BOOSTSYS)/include
BOOSTLIBDIR = -L$(BOOSTSYS)/lib

CC = g++ -std=c++11
FLAGS = -Wall -g $(BOOSTINCDIR) $(BOOSTLIBDIR)
COMPILE = $(CC) $(FLAGS) -c

$(EXE):$(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(BOOSTLIBS) $(OPENCVLIBS)

%.o:%.cpp
	$(COMPILE) $< -o $@

.PHONY:clean
clean:
	$(RM) -r $(OBJ) $(EXE)
