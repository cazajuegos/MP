#include<iostream>
#include "Pareja.h"
using namespace std;

Pareja::Pareja(){};

Pareja::Pareja(int i, int k){
  dato    = i;
  nveces  = k;
};

Pareja::Pareja(const Pareja& n){
  dato    = n.dato;
  nveces  = n.nveces;
};

void Pareja::show() const{
  cout << "El numero " << dato << " se repite " << nveces << "." << endl;
};

void Pareja::incrementar(int i){ nveces += i; };
int Pareja::getDato() const{ return dato; };

/* Constructor/Destructor */
Precuencia::Precuencia(){
  npares = 0;
  parejas = new Pareja[0];
};

Precuencia::Precuencia(const Precuencia& p){
  copy(p);
};

Precuencia::~Precuencia(){
  delete[] parejas;
};

/* get/set */
int Precuencia::getTotal() const{ return npares; };
void Precuencia::setPareja(int dato, int veces){
  int exist = -1;
  for(int i = 0; i < npares && exist < 0; i++){
    if(dato == parejas[i].getDato()){
      exist = i;
    }
  }
  if(exist >= 0){
    parejas[exist].incrementar(veces);
  }else{
    Pareja* nuevo = new Pareja[npares + 1];
    for(int i = 0; i < npares; i++){
      nuevo[i] = Pareja(parejas[i]);
    }
    nuevo[npares] = Pareja(dato, veces);
    delete[] parejas;
    parejas = nuevo;
    npares = npares + 1;
  }
};

/* Overload */
Precuencia& Precuencia::operator =(const Precuencia &n){
  if(this != &n){
    copy(n);
  }
  return *this;
};

void Precuencia::copy(const Precuencia& p){
  npares = p.npares;
  parejas = new Pareja[npares];
  for(int i = 0; i < npares; i++){
    parejas[i] = Pareja(p.parejas[i]);
  }
};

void Precuencia::show() const{
  cout << "Estas son las siguientes repeticiones:" << endl;
  for(int i = 0; i < npares; i++){
    parejas[i].show();
  }
};
