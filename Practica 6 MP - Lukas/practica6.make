# Compiler settings
CXX = g++
CXXFLAGS = -I./$(INCLUDE)

# Folder names
BIN = bin
OBJ = obj
SRC = src
INCLUDE = include

# --- Rules ---
.PHONY: all info clean mrproper

all: $(addprefix $(BIN)/, Barquitos BigInt Polilinea)

## make the executables files
## Compilacion Barcos.
$(BIN)/Barquitos: $(OBJ)/Main_Barquitos.o $(OBJ)/Barquitos.o
	$(CXX) -o $@ $^
## Compilacion numeros grandes.
$(BIN)/BigInt: $(OBJ)/Barquitos_Main.o $(OBJ)/BigInt.o
	$(CXX) -o $@ $^
## Compilacion Polilinea
$(BIN)/Polilinea: $(OBJ)/Polilinea_Main.o $(OBJ)/Polilinea.o
	$(CXX) -o $@ $^
## Compilacion Lista
$(BIN)/Lista: $(OBJ)/Lista_Main.o $(OBJ)/Lista.o
	$(CXX) -o $@ $^

## make .o files for executables
$(OBJ)/Barquitos_Main.o: $(SRC)/Main_Barquitos.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/BigInt_Main.o: $(SRC)/Main_Barquitos.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/Polilinea_Main.o: $(SRC)/Polilinea_Main.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/Lista_Main.o: $(SRC)/Lista_Main.o
	$(CXX) $(CXXFLAGS) -o $@ -c $<

## Compilacion de clases.
$(OBJ)/Barquitos.o: $(OBJ)/Barquitos.cpp $(INCLUDE)/Barquitos.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/BigInt.o: $(OBJ)/BigInt.cpp $(INCLUDE)/BigInt.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/Polilinea.o: $(OBJ)/Polilinea.cpp $(INCLUDE)/Polilinea.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/Lista.o: $(OBJ)/Lista.cpp $(INCLUDE)/Lista.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

info:
	@echo "Practica 6 realizado por Lukas Häring García."

clean:
	@echo "Limpiando objetos..."
	-@rm -f $(OBJ)/*.o

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm -f $(BIN)/*
