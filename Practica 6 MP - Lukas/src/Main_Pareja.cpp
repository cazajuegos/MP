#include<iostream>
#include "Pareja.h"
using namespace std;

int main(){
  Precuencia secuencia;
  char number[100];
  cout << "Introduzca el numero: ";
  cin.getline(number, 100);
  int i = 0;
  while(number[i] != '\0'){
    int n = number[i] - '0', m = 1;
    while(number[i + m] == number[i]) m++;
    secuencia.setPareja(n, m);
    i += m;
  }
  secuencia.show();
}
