OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

default: build

build:
$(OBJ)/utilidades.o: $(SRC)/utilidades.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/utilidades.o -I$(INC) $(SRC)/utilidades.cpp

$(OBJ)/01_RedimensionarArrayDinamico.o: $(SRC)/01_RedimensionarArrayDinamico.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/01_RedimensionarArrayDinamico.o -I$(INC) $(SRC)/01_RedimensionarArrayDinamico.cpp

$(OBJ)/02_Calificaciones_ArrayDinamicoStruct.o: $(SRC)/02_Calificaciones_ArrayDinamicoStruct.cpp $(INC)/utilidades.h
	g++ -c -o $(OBJ)/02_Calificaciones_ArrayDinamicoStruct.o -I$(INC) $(SRC)/02_Calificaciones_ArrayDinamicoStruct.cpp

$(LIB)/libutilidades.a: $(OBJ)/utilidades.o
	ar -rv $(LIB)/libutilidades.a $(OBJ)/utilidades.o

$(BIN)/01_RedimensionarArrayDinamico: $(OBJ)/01_RedimensionarArrayDinamico.o $(LIB)/libutilidades.a
	g++ -L$(LIB)/ -o $(BIN)/01_RedimensionarArrayDinamico $(OBJ)/01_RedimensionarArrayDinamico.o -lutilidades

$(BIN)/02_Calificaciones_ArrayDinamicoStruct: $(OBJ)/02_Calificaciones_ArrayDinamicoStruct.o $(LIB)/libutilidades.a
	g++ -L$(LIB)/ -o $(BIN)/02_Calificaciones_ArrayDinamicoStruct $(OBJ)/02_Calificaciones_ArrayDinamicoStruct.o -lutilidades

run1: build
	$(BIN)/01_RedimensionarArrayDinamico

run2: build
	$(BIN)/02_Calificaciones_ArrayDinamicoStruct

clean:
	@echo "Limpiando objetos y librerias..."
	-@rm  $(OBJ)/* $(LIB)/*

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm $(BIN)/*

list: 
	@echo "build\nrun1\nrun2\nclean\nmrproper"
