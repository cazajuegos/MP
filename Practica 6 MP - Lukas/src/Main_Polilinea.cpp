#include<iostream>
#include "Polilinea.h"
using namespace std;

int main(){
  Polilinea poli;
  int term = 0;
  do{
    int i, j;
    cout << "Introduzca x, y para el siguiente punto: ";
    cin >> i >> j;
    Punto nuevo(i, j);
    poli.setPunto(nuevo);
    cout << "-1 Para terminar, por lo contrario continuara:";
    cin >> term;
  }while(term != -1);

  poli.show();
  cout << endl;
}
