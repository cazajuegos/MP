#include <iostream>
#include "Conversiones_Matriz2D.h"

using namespace std;

int main(int argc, char const *argv[]){
  int F, C;

  cout << "MATRIZ2D_1" << endl;
  cout << "Introduzca numero de filas: ";
  cin >> F;
  cout << "Introduzca numero de columnas: ";
  cin >> C;
  int **matriz2d_1 = Crea_Matriz2D_1(F, C);
  Rellena_Aleatoriamente(matriz2d_1, F, C);
  Muestra_Matriz(matriz2d_1, F, C);
  cout << "\nPASO DE MATRIZ2D_1 A MATRIZ2D_2" << endl;
  int **copia_matriz2d_2 = Matriz2D_1_a_Matriz2D_2(matriz2d_1, F, C);
  Muestra_Matriz(copia_matriz2d_2, F, C);

  Borra_Matriz2D_1(matriz2d_1, F);
  Borra_Matriz2D_2(copia_matriz2d_2, F);

  return 0;
}
