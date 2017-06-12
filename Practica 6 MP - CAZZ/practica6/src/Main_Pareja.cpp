#include <iostream>
#include <cstdlib>
#include "Pareja.h"

using namespace std;

int main(){
  Precuencias secuencia;
  secuencia.Limpiar_Pantalla();
  cout << "-----------" << "\nPAREJA\n" << "-----------" << endl;

  char *numero = new char[100];
  cout << "Introduzca el numero: ";
  cin.getline(numero, 100);

  int i = 0;
  while(numero[i] != '\0'){
    int n = numero[i] - '0', m = 1;
    while(numero[i + m] == numero[i]) m++;
    secuencia.AgregarValor(n, m);
    i += m;
  }
  secuencia.Mostrar();
  delete [] numero;

  return 0;
}
