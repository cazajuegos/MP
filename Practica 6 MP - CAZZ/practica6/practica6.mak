OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/Barquitos $(BIN)/BigInt $(BIN)/Polilinea $(BIN)/Lista $(BIN)/MatrizDispersa $(BIN)/Skyline $(BIN)/Pareja

clean:
	@echo "Limpiando objetos y librerias..."
	-@rm  $(OBJ)/* $(LIB)/*

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm $(BIN)/*

info:
	@echo "Makefile Realizado por Francisco Rodriguez Jimenez (DNI: 77022734N)"

#COMPILACION DE OBJETOS
$(OBJ)/Barquitos.o: $(SRC)/Barquitos.cpp $(INC)/Barquitos.h
	g++ -c -o $(OBJ)/Barquitos.o -I$(INC) $(SRC)/Barquitos.cpp

$(OBJ)/BigInt.o: $(SRC)/BigInt.cpp $(INC)/BigInt.h
	g++ -c -o $(OBJ)/BigInt.o -I$(INC) $(SRC)/BigInt.cpp

$(OBJ)/Polilinea.o: $(SRC)/Polilinea.cpp $(INC)/Polilinea.h
	g++ -c -o $(OBJ)/Polilinea.o -I$(INC) $(SRC)/Polilinea.cpp

$(OBJ)/Lista.o: $(SRC)/Lista.cpp $(INC)/Lista.h
	g++ -c -o $(OBJ)/Lista.o -I$(INC) $(SRC)/Lista.cpp

$(OBJ)/MatrizDispersa.o: $(SRC)/MatrizDispersa.cpp $(INC)/MatrizDispersa.h
	g++ -c -o $(OBJ)/MatrizDispersa.o -I$(INC) $(SRC)/MatrizDispersa.cpp

$(OBJ)/Skyline.o: $(SRC)/Skyline.cpp $(INC)/Skyline.h
	g++ -c -o $(OBJ)/Skyline.o -I$(INC) $(SRC)/Skyline.cpp

$(OBJ)/Pareja.o: $(SRC)/Pareja.cpp $(INC)/Pareja.h
	g++ -c -o $(OBJ)/Pareja.o -I$(INC) $(SRC)/Pareja.cpp

#COMPILACION DEL MAIN
$(OBJ)/Main_Barquitos.o: $(SRC)/Main_Barquitos.cpp $(INC)/Barquitos.h
	g++ -c -o $(OBJ)/Main_Barquitos.o -I$(INC) $(SRC)/Main_Barquitos.cpp

$(OBJ)/Main_BigInt.o: $(SRC)/Main_BigInt.cpp $(INC)/Barquitos.h
	g++ -c -o $(OBJ)/Main_BigInt.o -I$(INC) $(SRC)/Main_BigInt.cpp

$(OBJ)/Main_Polilinea.o: $(SRC)/Main_Polilinea.cpp $(INC)/Polilinea.h
	g++ -c -o $(OBJ)/Main_Polilinea.o -I$(INC) $(SRC)/Main_Polilinea.cpp

$(OBJ)/Main_Lista.o: $(SRC)/Main_Lista.cpp $(INC)/Lista.h
	g++ -c -o $(OBJ)/Main_Lista.o -I$(INC) $(SRC)/Main_Lista.cpp

$(OBJ)/Main_MatrizDispersa.o: $(SRC)/Main_MatrizDispersa.cpp $(INC)/MatrizDispersa.h
	g++ -c -o $(OBJ)/Main_MatrizDispersa.o -I$(INC) $(SRC)/Main_MatrizDispersa.cpp

$(OBJ)/Main_Skyline.o: $(SRC)/Main_Skyline.cpp $(INC)/Skyline.h
	g++ -c -o $(OBJ)/Main_Skyline.o -I$(INC) $(SRC)/Main_Skyline.cpp

$(OBJ)/Main_Pareja.o: $(SRC)/Main_Pareja.cpp $(INC)/Pareja.h
	g++ -c -o $(OBJ)/Main_Pareja.o -I$(INC) $(SRC)/Main_Pareja.cpp

#CREACION DE LIBRERIAS
$(LIB)/libBarquitos.a: $(OBJ)/Barquitos.o
	ar -rv $(LIB)/libBarquitos.a $(OBJ)/Barquitos.o

$(LIB)/libBigInt.a: $(OBJ)/BigInt.o
	ar -rv $(LIB)/libBigInt.a $(OBJ)/BigInt.o

$(LIB)/libPolilinea.a: $(OBJ)/Polilinea.o
	ar -rv $(LIB)/libPolilinea.a $(OBJ)/Polilinea.o

$(LIB)/libLista.a: $(OBJ)/Lista.o
	ar -rv $(LIB)/libLista.a $(OBJ)/Lista.o

$(LIB)/libMatrizDispersa.a: $(OBJ)/MatrizDispersa.o
	ar -rv $(LIB)/libMatrizDispersa.a $(OBJ)/MatrizDispersa.o

$(LIB)/libSkyline.a: $(OBJ)/Skyline.o
	ar -rv $(LIB)/libSkyline.a $(OBJ)/Skyline.o

$(LIB)/libPareja.a: $(OBJ)/Pareja.o
	ar -rv $(LIB)/libPareja.a $(OBJ)/Pareja.o

#CREACION DE EJECUTABLES
$(BIN)/Barquitos: $(OBJ)/Main_Barquitos.o $(LIB)/libBarquitos.a
	g++ -L$(LIB)/ -o $(BIN)/Barquitos $(OBJ)/Main_Barquitos.o -lBarquitos

$(BIN)/BigInt: $(OBJ)/Main_BigInt.o $(LIB)/libBigInt.a
	g++ -L$(LIB)/ -o $(BIN)/BigInt $(OBJ)/Main_BigInt.o -lBigInt

$(BIN)/Polilinea: $(OBJ)/Main_Polilinea.o $(LIB)/libPolilinea.a
	g++ -L$(LIB)/ -o $(BIN)/Polilinea $(OBJ)/Main_Polilinea.o -lPolilinea

$(BIN)/Lista: $(OBJ)/Main_Lista.o $(LIB)/libLista.a
	g++ -L$(LIB)/ -o $(BIN)/Lista $(OBJ)/Main_Lista.o -lLista

$(BIN)/MatrizDispersa: $(OBJ)/Main_MatrizDispersa.o $(LIB)/libMatrizDispersa.a
	g++ -L$(LIB)/ -o $(BIN)/MatrizDispersa $(OBJ)/Main_MatrizDispersa.o -lMatrizDispersa

$(BIN)/Skyline: $(OBJ)/Main_Skyline.o $(LIB)/libSkyline.a
	g++ -L$(LIB)/ -o $(BIN)/Skyline $(OBJ)/Main_Skyline.o -lSkyline

$(BIN)/Pareja: $(OBJ)/Main_Pareja.o $(LIB)/libPareja.a
	g++ -L$(LIB)/ -o $(BIN)/Pareja $(OBJ)/Main_Pareja.o -lPareja
