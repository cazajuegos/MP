OBJ=obj
BIN=bin
LIB=lib
SRC=src
INC=include

all: $(BIN)/04_Dinamic_Matriz2D_1 $(BIN)/05_Dinamic_Matriz2D_2 $(BIN)/06_Copia_2D_1_en_2D_2 $(BIN)/06_Copia_2D_2_en_2D_1

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

$(OBJ)/Matriz2D_2.o: $(SRC)/Matriz2D_2.cpp $(INC)/Matriz2D_2.h
	g++ -c -o $(OBJ)/Matriz2D_2.o -I$(INC) $(SRC)/Matriz2D_2.cpp

$(OBJ)/Conversiones_Matriz2D.o: $(SRC)/Conversiones_Matriz2D.cpp $(INC)/Conversiones_Matriz2D.h
	g++ -c -o $(OBJ)/Conversiones_Matriz2D.o -I$(INC) $(SRC)/Conversiones_Matriz2D.cpp

$(OBJ)/04_Dinamic_Matriz2D_1.o: $(SRC)/04_Dinamic_Matriz2D_1.cpp $(INC)/Matriz2D_1.h
	g++ -c -o $(OBJ)/04_Dinamic_Matriz2D_1.o -I$(INC) $(SRC)/04_Dinamic_Matriz2D_1.cpp

$(OBJ)/05_Dinamic_Matriz2D_2.o: $(SRC)/05_Dinamic_Matriz2D_2.cpp $(INC)/Matriz2D_2.h
	g++ -c -o $(OBJ)/05_Dinamic_Matriz2D_2.o -I$(INC) $(SRC)/05_Dinamic_Matriz2D_2.cpp

$(OBJ)/06_Copia_2D_1_en_2D_2.o: $(SRC)/06_Copia_2D_1_en_2D_2.cpp $(INC)/Conversiones_Matriz2D.h
	g++ -c -o $(OBJ)/06_Copia_2D_1_en_2D_2.o -I$(INC) $(SRC)/06_Copia_2D_1_en_2D_2.cpp

$(OBJ)/06_Copia_2D_2_en_2D_1.o: $(SRC)/06_Copia_2D_2_en_2D_1.cpp $(INC)/Conversiones_Matriz2D.h
	g++ -c -o $(OBJ)/06_Copia_2D_2_en_2D_1.o -I$(INC) $(SRC)/06_Copia_2D_2_en_2D_1.cpp

$(LIB)/libMatriz2D_1.a: $(OBJ)/Matriz2D_1.o
	ar -rv $(LIB)/libMatriz2D_1.a $(OBJ)/Matriz2D_1.o

$(LIB)/libMatriz2D_2.a: $(OBJ)/Matriz2D_2.o
	ar -rv $(LIB)/libMatriz2D_2.a $(OBJ)/Matriz2D_2.o

$(LIB)/libConversiones_Matriz2D.a: $(OBJ)/Conversiones_Matriz2D.o
	ar -rv $(LIB)/libConversiones_Matriz2D.a $(OBJ)/Conversiones_Matriz2D.o

$(BIN)/04_Dinamic_Matriz2D_1: $(OBJ)/04_Dinamic_Matriz2D_1.o $(LIB)/libMatriz2D_1.a
	g++ -L$(LIB)/ -o $(BIN)/04_Dinamic_Matriz2D_1 $(OBJ)/04_Dinamic_Matriz2D_1.o -lMatriz2D_1

$(BIN)/05_Dinamic_Matriz2D_2: $(OBJ)/05_Dinamic_Matriz2D_2.o $(LIB)/libMatriz2D_2.a
	g++ -L$(LIB)/ -o $(BIN)/05_Dinamic_Matriz2D_2 $(OBJ)/05_Dinamic_Matriz2D_2.o -lMatriz2D_2

$(BIN)/06_Copia_2D_1_en_2D_2: $(OBJ)/06_Copia_2D_1_en_2D_2.o $(LIB)/libConversiones_Matriz2D.a
	g++ -L$(LIB)/ -o $(BIN)/06_Copia_2D_1_en_2D_2 $(OBJ)/06_Copia_2D_1_en_2D_2.o -lConversiones_Matriz2D

$(BIN)/06_Copia_2D_2_en_2D_1: $(OBJ)/06_Copia_2D_2_en_2D_1.o $(LIB)/libConversiones_Matriz2D.a
	g++ -L$(LIB)/ -o $(BIN)/06_Copia_2D_2_en_2D_1 $(OBJ)/06_Copia_2D_2_en_2D_1.o -lConversiones_Matriz2D
