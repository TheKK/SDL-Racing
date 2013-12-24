CXX = g++
CXXFLAGS = -Wall

SRC = $(PWD)/src/*.cpp
INCLUDE = -I $(PWD)/include

OBJ = main.o game.o configLoader.o

LIB = -llua5.2 -lSDL2main -lSDL2

OUT_EXE = racing

$(OUT_EXE): $(OBJ)
	$(CXX) $(SRC) $(CXXFLAGS) $(INCLUDE) $(LIB) -g -o $@


%.o: $(PWD)/src/%.cpp 
	$(CXX) $< $(CXXFLAG) $(INCLUDE) $(LIBS) -c
