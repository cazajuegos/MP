#include <iostream>
#include <cstdlib>
#include "Skyline.h"

using namespace std;

int main(){
  Skyline sky;
  double inc_abscisa, fin_abcisa, altura;
  sky.LimpiarPantalla();

  cout << "--------" << "\nSKYLINE\n" << "--------" << endl;
  cout << "Para dejar de introducir valores, altura = 0" << endl;

  cout << "Introduzca un intervalo de abscisas: ";
  cin >> inc_abscisa >> fin_abcisa;
  cout << "Introduzca la altura: ";
  cin >> altura;
  while(altura != 0){
    sky.setSkyline(inc_abscisa, fin_abcisa, altura);
    cout << "--------------------------------------------"<< endl;
    cout << "Introduzca un intervalo de abscisas: ";
    cin >> inc_abscisa >> fin_abcisa;
    cout << "Introduzca la altura: ";
    cin >> altura;
  }
  sky.LimpiarPantalla();
  sky.Muestra();
  return 0;
}
