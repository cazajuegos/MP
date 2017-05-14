#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matriz2D_2.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int F, C;
  int ** matriz;
  int ** copia_matriz;
  int ** submatriz;
  int ** traspuesta;
  int ** inversa;

  cout << "Introduzca las filas: ";
  cin >> F;
  cout << "Introduzca las columnas: ";
  cin >> C;

  Limpia_Consola();

  //INICIALIZACION ALEATORIA
  cout << "CREA MATRIZ ALEATORIA" << endl;
  matriz = Crea_Rellena_Aleatoriamente(F, C);
  Muestra_Matriz(matriz, F, C);

  //COPIA
  cout << "\nCOPIA MATRIZ" << endl;
  copia_matriz = Copia_Matriz(matriz, F, C);
  Muestra_Matriz(matriz, F, C);

  //SUBMATRIZ
  cout << "\nCREA SUBMATRIZ" << endl;
  int inicio_F, inicio_C, fin_F, fin_C;

  cout << "Inicio y fin de fila: ";
  cin >> inicio_F >> fin_F;
  cout << "Inicio y fin de columna: ";
  cin >> inicio_C >> fin_C;

  submatriz = Submatriz(matriz, inicio_F, inicio_C, fin_F, fin_C);
  Muestra_Matriz(submatriz, fin_F-inicio_F+1, fin_C-inicio_C+1);

  //ELIMINA FILA
  cout << "\nELIMINA FILA" << endl;
  int fila_borrar;
  int **matriz_f;

  cout << "Fila a eliminar: ";
  cin >> fila_borrar;

  matriz_f = Elimina_Fila(matriz, F, C, fila_borrar);
  Muestra_Matriz(matriz_f, F-1, C);

  //ELIMINA COLUMNA
  cout << "\nELIMINA COLUMNA" << endl;
  int col_borrar;
  int **matriz_c;

  cout << "Columna a eliminar: ";
  cin >> col_borrar;

  matriz_c = Elimina_Columna(matriz, F, C, col_borrar);
  Muestra_Matriz(matriz_c, F, C-1);

  //MATRIZ TRASPUESTA
  cout << "\nMATRIZ TRASPUESTA" << endl;
  traspuesta = Traspuesta(matriz, F, C);
  Muestra_Matriz(traspuesta, C, F);

  //MATRIZ INVERSA
  cout << "\nMATRIZ INVERSA" << endl;
  inversa = Filas_Inv(matriz, F, C);
  Muestra_Matriz(inversa, F, C);

  Borra_Matriz2D_2(matriz, F);
  Borra_Matriz2D_2(copia_matriz, F);
  Borra_Matriz2D_2(submatriz, fin_F-inicio_F+1);
  Borra_Matriz2D_2(traspuesta, F);
  Borra_Matriz2D_2(inversa, F);
  Borra_Matriz2D_2(matriz_f, F-1);
  Borra_Matriz2D_2(matriz_c, F);
  return 0;
}
