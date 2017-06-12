OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/DemosCadenasClasicas $(BIN)/PosicionPrimerBlanco $(BIN)/SaltaPrimeraPalabra

clean:
	echo "Limpiando..."
	rm $(OBJ)/* $(LIB)/*  

mrproper: clean
	rm $(BIN)/*

$(OBJ)/miCadenaClasica.o: $(SRC)/miCadenaClasica.cpp include/miCadenaClasica.h
	g++ -c -o $(OBJ)/miCadenaClasica.o -I$(INC) $(SRC)/miCadenaClasica.cpp

$(OBJ)/DemosCadenasClasicas.o: $(SRC)/DemosCadenasClasicas.cpp include/miCadenaClasica.h
	g++ -c -o $(OBJ)/DemosCadenasClasicas.o -I$(INC) $(SRC)/DemosCadenasClasicas.cpp

$(OBJ)/PosicionPrimerBlanco.o: $(SRC)/PosicionPrimerBlanco.cpp
	g++ -c -o $(OBJ)/PosicionPrimerBlanco.o $(SRC)/PosicionPrimerBlanco.cpp

$(OBJ)/SaltaPrimeraPalabra.o: $(SRC)/SaltaPrimeraPalabra.cpp
	g++ -c -o $(OBJ)/SaltaPrimeraPalabra.o $(SRC)/SaltaPrimeraPalabra.cpp

$(LIB)/libcadena.a: $(OBJ)/miCadenaClasica.o
	ar rvs $(LIB)/libcadena.a $(OBJ)/miCadenaClasica.o

$(BIN)/DemosCadenasClasicas: $(OBJ)/DemosCadenasClasicas.o $(LIB)/libcadena.a
	g++ -L$(LIB)/ -o $(BIN)/DemosCadenasClasicas $(OBJ)/DemosCadenasClasicas.o -lcadena

$(BIN)/PosicionPrimerBlanco: $(OBJ)/PosicionPrimerBlanco.o
	g++ -o $(BIN)/PosicionPrimerBlanco $(OBJ)/PosicionPrimerBlanco.o

$(BIN)/SaltaPrimeraPalabra: $(OBJ)/SaltaPrimeraPalabra.o
	g++ -o $(BIN)/SaltaPrimeraPalabra $(OBJ)/SaltaPrimeraPalabra.o
