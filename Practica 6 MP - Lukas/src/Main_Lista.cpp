#include<iostream>
#include "Lista.h"
using namespace std;

int main(){
  Lista nuevalista0;
  nuevalista0.create();
  nuevalista0.show();
  Lista nuevalista1;
  nuevalista1.create();
  nuevalista1.show();

  cout << "La lista concatenada es: " << endl;
  Lista sumalistas = nuevalista0 + nuevalista1;
  sumalistas.show();
  int valor;
  cout << "Que valor quiere borrar? ";
  cin >> valor;
  sumalistas[valor];
  sumalistas.show();
}
