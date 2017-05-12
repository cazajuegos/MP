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

all: $(addprefix $(BIN)/, Barquitos)

## make the executables files
$(BIN)/Barquitos: $(OBJ)/Barquitos.o
	$(CXX) -o $@ $^

## make .o files for executables
$(OBJ)/Barquitos.o: $(SRC)/Barquitos.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<


info:
	@echo "Proyecto realizado por Lukas Häring García."

clean:
	@echo "Limpiando objetos..."
	-@rm -f $(OBJ)/*.o

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm -f $(BIN)/*
