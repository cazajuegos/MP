OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/16_PosMayor $(BIN)/17_OrdenConPunteros $(BIN)/18_Calificaciones_ArrayStruct $(BIN)/19_Calificaciones_ArrayStruct_Ordenado

clean:
	@echo "Limpiando objetos y librerias..."
	-@rm  $(OBJ)/* $(LIB)/*

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm $(BIN)/*

info:
	@echo "Makefile Realizado por Francisco Rodriguez Jimenez (DNI: 77022734N)"

$(OBJ)/funcionesptr.o: $(SRC)/funcionesptr.cpp $(INC)/funcionesptr.h
	g++ -c -o $(OBJ)/funcionesptr.o -I$(INC) $(SRC)/funcionesptr.cpp

$(OBJ)/funcionescalif.o: $(SRC)/funcionescalif.cpp $(INC)/funcionescalif.h
	g++ -c -o $(OBJ)/funcionescalif.o -I$(INC) $(SRC)/funcionescalif.cpp

$(OBJ)/16_PosMayor.o: $(SRC)/16_PosMayor.cpp $(INC)/funcionesptr.h
	g++ -c -o $(OBJ)/16_PosMayor.o -I$(INC) $(SRC)/16_PosMayor.cpp

$(OBJ)/17_OrdenConPunteros.o: $(SRC)/17_OrdenConPunteros.cpp $(INC)/funcionesptr.h
	g++ -c -o $(OBJ)/17_OrdenConPunteros.o -I$(INC) $(SRC)/17_OrdenConPunteros.cpp

$(OBJ)/18_Calificaciones_ArrayStruct.o: $(SRC)/18_Calificaciones_ArrayStruct.cpp $(INC)/funcionescalif.h
	g++ -c -o $(OBJ)/18_Calificaciones_ArrayStruct.o -I$(INC) $(SRC)/18_Calificaciones_ArrayStruct.cpp

$(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o: $(SRC)/19_Calificaciones_ArrayStruct_Ordenado.cpp $(INC)/funcionescalif.h
	g++ -c -o $(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o -I$(INC) $(SRC)/19_Calificaciones_ArrayStruct_Ordenado.cpp

$(LIB)/libptr.a: $(OBJ)/funcionesptr.o
	ar -rv $(LIB)/libptr.a $(OBJ)/funcionesptr.o

$(LIB)/libcalif.a: $(OBJ)/funcionescalif.o
	ar -rv $(LIB)/libcalif.a $(OBJ)/funcionescalif.o

$(BIN)/16_PosMayor: $(OBJ)/16_PosMayor.o $(LIB)/libptr.a
	g++ -L$(LIB)/ -o $(BIN)/16_PosMayor $(OBJ)/16_PosMayor.o -lptr

$(BIN)/17_OrdenConPunteros: $(OBJ)/17_OrdenConPunteros.o $(LIB)/libptr.a
	g++ -L$(LIB)/ -o $(BIN)/17_OrdenConPunteros $(OBJ)/17_OrdenConPunteros.o -lptr

$(BIN)/18_Calificaciones_ArrayStruct: $(OBJ)/18_Calificaciones_ArrayStruct.o $(LIB)/libcalif.a
	g++ -L$(LIB)/ -o $(BIN)/18_Calificaciones_ArrayStruct $(OBJ)/18_Calificaciones_ArrayStruct.o -lcalif

$(BIN)/19_Calificaciones_ArrayStruct_Ordenado: $(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o $(LIB)/libcalif.a
	g++ -L$(LIB)/ -o $(BIN)/19_Calificaciones_ArrayStruct_Ordenado $(OBJ)/19_Calificaciones_ArrayStruct_Ordenado.o -lcalif
