#include <iostream>
#include "Conversiones_Matriz2D.h"

using namespace std;

int main(int argc, char const *argv[]){
  int F1, C1;

  cout << "\nMATRIZ2D_2" << endl;
  cout << "Introduzca numero de filas: ";
  cin >> F1;
  cout << "Introduzca numero de columnas: ";
  cin >> C1;
  int **matriz2d_2 = Crea_Matriz2D_2(F1, C1);
  Rellena_Aleatoriamente(matriz2d_2, F1, C1);
  Muestra_Matriz(matriz2d_2, F1, C1);
  cout << "\nPASO DE MATRIZ2D_2 A MATRIZ2D_1" << endl;
  int **copia_matriz2d_1 = Matriz2D_2_a_Matriz2D_1(matriz2d_2, F1, C1);
  Muestra_Matriz(copia_matriz2d_1, F1, C1);

  Borra_Matriz2D_2(matriz2d_2, F1);
  Borra_Matriz2D_1(copia_matriz2d_1, F1);

  return 0;
}
