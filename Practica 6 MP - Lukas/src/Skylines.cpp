#include<iostream>
#include "../include/Skylines.h"
using namespace std;

/* Constructor/Destructor */
Skylines::Skylines(){
  n = 0;
  abscisas = new double[0];
  alturas = new double[0];
};

Skylines::Skylines(const Skylines& sk){
  copy(sk);
};

Skylines::~Skylines(){
  delete[] abscisas;
  delete[] alturas;
}

/* get/set */
int Skylines::getTotal() const{ return n; };
void Skylines::setSkyline(double ini, double fin, double altura){
  bool exi = false;
  int  prc = 0, siz = 0;
  for(int i = 0; i < n; i++){
    if(abscisas[i] >= ini && abscisas[i] <= fin){
      exi = true;
      prc = i;
      siz++;
    }
  }
  abscisas  = new double[n - siz + 2];
  alturas   = new double[n - siz + 1];
  int k = prc - siz;
  cout << k << "<- "<< endl;
  for(int i = 0; i < k; i++){
    abscisas[i] = abscisas[i];
    alturas[i]  = alturas[i];
  }
  abscisas[k] = ini;
  abscisas[k + 1] = fin;
  alturas[k] = altura;
  for(int i = prc; i < n; i++){
    abscisas[i - prc + k + 2] = abscisas[i];
    alturas[i - prc + k + 1]  = alturas[i];
  }

  n += 2 - siz;
};

/* Overload */
Skylines& Skylines::operator =(const Skylines &n){
  if(this != &n){
    copy(n);
  }
  return *this;
};

void Skylines::copy(const Skylines& sk){
  n = sk.n;
  abscisas = new double[n];
  alturas = new double[n];
  for(int i = 0; i < n; i++){
    abscisas[i] = sk.abscisas[i];
    alturas[i] = sk.alturas[i];
  }
};

void Skylines::show() const{
  cout << "Vista previa de los edificios:" << endl;
  for(int i = 0; i < n; i+=2){
    cout << "[" << abscisas[i] << ", " << abscisas[i + 1] << "] = " << alturas[i] << "." << endl;
  }
};

int main(){
  Skylines sky;
  char s = 'n';
  do{
    cout << "->Introducir un edificio<- " << endl;
    double ini, fin, size;
    cout << "Introduzca el principio del intervalo: ";
    cin >> ini;
    cout << "Introduzca el fin del intervalo: ";
    cin >> fin;
    cout << "Introduzca la altura: ";
    cin >> size;
    sky.setSkyline(ini, fin, size);
    cout << "Para terminar (s): ";
    cin >> s;
  }while(s != 's');
  sky.show();
}
