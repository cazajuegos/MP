#include <iostream>
#include <cstdlib>
#include "Pareja.h"

using namespace std;

Pareja::Pareja(){
  dato = 0;
  nveces = 0;
};

Pareja::Pareja(int _dato, int _nveces){
  dato = _dato;
  nveces = _nveces;
};

Pareja::Pareja(const Pareja &p){
  dato = p.dato;
  nveces = p.nveces;
};

int Pareja::GetDato()const { return dato;};
int Pareja::GetVeces()const {return nveces;};
void Pareja::incrementar(int i){ nveces += i; };
void Pareja::Mostrar() const{
  cout << "El numero " << dato << " se repite " << nveces << "." << endl;
};

Precuencias::Precuencias(){
  parejas = new Pareja[0];
  npares = 0;
};

Precuencias::Precuencias(const Precuencias &l){
  npares = l.npares;
  parejas = new Pareja[npares];
  for(int i = 0; i < npares; i++){
    parejas[i] = l.parejas[i];
  }
};

Precuencias::~Precuencias(){
  delete [] parejas;
};

void Precuencias::AgregarValor(int dato, int veces){
  int existe = -1;
  for(int i = 0; i < npares && existe < 0; i++){
    if(dato == parejas[i].GetDato()){
      existe = i;
    }
  }

  if(existe >= 0){
    parejas[existe].incrementar(veces);
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

void Precuencias::Mostrar() const{
  cout << "Repeticiones:" << endl;
  for(int i = 0; i < npares; i++){
    parejas[i].Mostrar();
  }
};

void Precuencias::Limpiar_Pantalla(){ system("/usr/bin/clear");};
