#include <iostream>
#include "Polilinea.h"

using namespace std;

int main(){
  Polilinea poli;
  Punto p1;
  int x, y;
  char respuesta;

  system("/usr/bin/clear");
  cout << "---------" << "\nPOLILINEA\n" << "---------" << endl;
  cout << "¿Desea introducir Puntos a la Polilinea(Y/N)? ";
  cin >> respuesta;

  while(toupper(respuesta) != 'N'){
    cout << "Introduzca (x): ";
    cin >> x;
    cout << "Introduzca (y): ";
    cin >> y;
    p1 = Punto(x, y);
    poli.Aniade(p1);
    cout << "\n¿Desea seguir añadiendo mas puntos(Y/N)? ";
    cin >> respuesta;
  }

  system("/usr/bin/clear");

  cout << "POLILINEA: " << endl;
  poli.Mostrar();

  return 0;
}
