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

all: $(addprefix $(BIN)/, 01_RedimensionarArrayDinamico 02_Calificaciones_ArrayDinamicoStruct_ordenado)

## make the executables files
$(BIN)/01_RedimensionarArrayDinamico: $(OBJ)/01_RedimensionarArrayDinamico.o
	$(CXX) -o $@ $^

$(BIN)/02_Calificaciones_ArrayDinamicoStruct_ordenado: $(OBJ)/02_Calificaciones_ArrayDinamicoStruct_ordenado.o
	$(CXX) -o $@ $^

## make .o files for executables
$(OBJ)/01_RedimensionarArrayDinamico.o: $(SRC)/01_RedimensionarArrayDinamico.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ)/02_Calificaciones_ArrayDinamicoStruct_ordenado.o: $(SRC)/02_Calificaciones_ArrayDinamicoStruct_ordenado.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

info:
	@echo "Proyecto realizado por Lukas Häring García."

clean:
	@echo "Limpiando objetos..."
	-@rm -f $(OBJ)/*.o

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm -f $(BIN)/*
