OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/Barquitos

clean:
	@echo "Limpiando objetos y librerias..."
	-@rm  $(OBJ)/* $(LIB)/*

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm $(BIN)/*

info:
	@echo "Makefile Realizado por Francisco Rodriguez Jimenez (DNI: 77022734N)"

$(OBJ)/Barquitos.o: $(SRC)/Barquitos.cpp $(INC)/Barquitos.h
	g++ -c -o $(OBJ)/Barquitos.o -I$(INC) $(SRC)/Barquitos.cpp

$(OBJ)/Main_Barquitos.o: $(SRC)/Main_Barquitos.cpp $(INC)/Barquitos.h
	g++ -c -o $(OBJ)/Main_Barquitos.o -I$(INC) $(SRC)/Main_Barquitos.cpp

$(LIB)/libBarquitos.a: $(OBJ)/Barquitos.o
	ar -rv $(LIB)/libBarquitos.a $(OBJ)/Barquitos.o

$(BIN)/Barquitos: $(OBJ)/Main_Barquitos.o $(LIB)/libBarquitos.a
	g++ -L$(LIB)/ -o $(BIN)/Barquitos $(OBJ)/Main_Barquitos.o -lBarquitos
