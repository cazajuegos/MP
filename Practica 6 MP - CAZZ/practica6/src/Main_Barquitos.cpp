#include <iostream>
#include <cstdlib>
#include "Barquitos.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int filas, columnas, x, z, tam;
  char posicion, respuesta, y;

  system("/usr/bin/clear");
  cout << "####################################BARQUITOS###################################\n";
  cout << "Dimensiones del tablero: " << endl;
  cout << "Filas: "; cin >> filas;
  cout << "Columnas: "; cin >> columnas; cout << endl;
  cout << "__________________________________________________________________________" << endl;

  Barquitos* tablero = new Barquitos(filas, columnas);

  tablero->Limpiar();
  tablero->Muestra();

  cout << "\n¿Desea posicionar un barco(Y/N)? ";
  cin >> respuesta;
  while(toupper(respuesta) == 'Y'){
    cout << "Introduzca la posicion: ";
    cin >> x >> y;
    z = y - 'A';
    cout << "Introduzca el tamanio: ";
    cin >> tam;
    cout << "Horizontal(H), Vertical(V): ";
    cin >> posicion;

    tablero->Limpiar();
    tablero->Poner_Barcos(x-1, z, tam, posicion);
    tablero->Muestra();

    cout << "\nDesea posicionar un barco(y/n)?";
    cin >> respuesta;
  }

  tablero->Limpiar();
  tablero->Muestra();
  tablero->Dispara();

  delete tablero;

  return 0;
}
