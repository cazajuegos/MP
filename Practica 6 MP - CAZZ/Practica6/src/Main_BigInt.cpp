#include <iostream>
#include <string>
#include <cstdlib>
#include "BigInt.h"

using namespace std;

int main(){
  system("/usr/bin/clear");
  BigInt numero1;
  numero1.Lee_Numero();
  BigInt numero2;
  numero2.Lee_Numero();
  system("/usr/bin/clear");
  cout << "Primer numero: ";
  numero1.Muestra();
  cout << "\nSegundo numero: ";
  numero2.Muestra();
  BigInt Suma = numero1.Suma(numero2);
  cout << "\n---------------------";
  cout << "\nLa suma es: ";
  Suma.Muestra();
  cout << endl;

  return 0;
}
