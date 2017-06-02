OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/Barquitos $(BIN)/BigInt $(BIN)/Polilinea

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

$(OBJ)/BigInt.o: $(SRC)/BigInt.cpp $(INC)/BigInt.h
	g++ -c -o $(OBJ)/BigInt.o -I$(INC) $(SRC)/BigInt.cpp

$(OBJ)/Polilinea.o: $(SRC)/Polilinea.cpp $(INC)/Polilinea.h
	g++ -c -o $(OBJ)/Polilinea.o -I$(INC) $(SRC)/Polilinea.cpp

$(OBJ)/Main_Barquitos.o: $(SRC)/Main_Barquitos.cpp $(INC)/Barquitos.h
	g++ -c -o $(OBJ)/Main_Barquitos.o -I$(INC) $(SRC)/Main_Barquitos.cpp

$(OBJ)/Main_BigInt.o: $(SRC)/Main_BigInt.cpp $(INC)/Barquitos.h
	g++ -c -o $(OBJ)/Main_BigInt.o -I$(INC) $(SRC)/Main_BigInt.cpp

$(OBJ)/Main_Polilinea.o: $(SRC)/Main_Polilinea.cpp $(INC)/Polilinea.h
	g++ -c -o $(OBJ)/Main_Polilinea.o -I$(INC) $(SRC)/Main_Polilinea.cpp

$(LIB)/libBarquitos.a: $(OBJ)/Barquitos.o
	ar -rv $(LIB)/libBarquitos.a $(OBJ)/Barquitos.o

$(LIB)/libBigInt.a: $(OBJ)/BigInt.o
	ar -rv $(LIB)/libBigInt.a $(OBJ)/BigInt.o

$(LIB)/libPolilinea.a: $(OBJ)/Polilinea.o
	ar -rv $(LIB)/libPolilinea.a $(OBJ)/Polilinea.o

$(BIN)/Barquitos: $(OBJ)/Main_Barquitos.o $(LIB)/libBarquitos.a
	g++ -L$(LIB)/ -o $(BIN)/Barquitos $(OBJ)/Main_Barquitos.o -lBarquitos

$(BIN)/BigInt: $(OBJ)/Main_BigInt.o $(LIB)/libBigInt.a
	g++ -L$(LIB)/ -o $(BIN)/BigInt $(OBJ)/Main_BigInt.o -lBigInt

$(BIN)/Polilinea: $(OBJ)/Main_Polilinea.o $(LIB)/libPolilinea.a
	g++ -L$(LIB)/ -o $(BIN)/Polilinea $(OBJ)/Main_Polilinea.o -lPolilinea
