# Compiler settings
CXX = g++ -g
CXXFLAGS = -I./$(INCLUDE)

# Folder names
BIN = bin
OBJ = obj
SRC = src
INCLUDE = include

# --- Rules ---
.PHONY: all info clean mrproper

all: $(addprefix $(BIN)/, ejercicios)

## make the executables files
$(BIN)/ejercicios: $(OBJ)/ejercicios.o
	$(CXX) -o $@ $^

## make .o files for executables
$(OBJ)/ejercicios.o: $(SRC)/ejercicios.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

info:
	@echo "Proyecto realizado por Lukas Häring García."

clean:
	@echo "Limpiando objetos..."
	-@rm -f $(OBJ)/*.o

mrproper: clean
	@echo "Limpiando ejecutables..."
	-@rm -f $(BIN)/*
