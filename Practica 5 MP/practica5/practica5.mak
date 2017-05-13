OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/04_Dinamic_Matriz2D_1

clean:
	@echo "Limpiando objetos y librerias..."
	-@rm  $(OBJ)/* $(LIB)/*

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm $(BIN)/*

info:
	@echo "Makefile Realizado por Francisco Rodriguez Jimenez (DNI: 77022734N)"

$(OBJ)/Matriz2D_1.o: $(SRC)/Matriz2D_1.cpp $(INC)/Matriz2D_1.h
	g++ -c -o $(OBJ)/Matriz2D_1.o -I$(INC) $(SRC)/Matriz2D_1.cpp

$(OBJ)/04_Dinamic_Matriz2D_1.o: $(SRC)/04_Dinamic_Matriz2D_1.cpp $(INC)/Matriz2D_1.h
	g++ -c -o $(OBJ)/04_Dinamic_Matriz2D_1.o -I$(INC) $(SRC)/04_Dinamic_Matriz2D_1.cpp

$(LIB)/libMatriz2D_1.a: $(OBJ)/Matriz2D_1.o
	ar -rv $(LIB)/libMatriz2D_1.a $(OBJ)/Matriz2D_1.o

$(BIN)/04_Dinamic_Matriz2D_1: $(OBJ)/04_Dinamic_Matriz2D_1.o $(LIB)/libMatriz2D_1.a
	g++ -L$(LIB)/ -o $(BIN)/04_Dinamic_Matriz2D_1 $(OBJ)/04_Dinamic_Matriz2D_1.o -lMatriz2D_1
