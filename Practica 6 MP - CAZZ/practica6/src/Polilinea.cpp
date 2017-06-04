#include <iostream>
#include "Polilinea.h"

using namespace std;

Punto::Punto(){
  x = 0;
  y = 0;
};

Punto::Punto(int _x, int _y){
  x = _x;
  y = _y;
};

Punto::Punto(const Punto &l){
  x = l.x;
  y = l.y;
};

int Punto::getX() const{
  return x;
};

int Punto::getY() const{
  return y;
};

Polilinea::Polilinea(){
  num = 0;
  p = new Punto[0];
};

Polilinea::~Polilinea(){
  delete [] p;
};

Polilinea::Polilinea(const Polilinea &l){
  num = l.num;
  p = new Punto[num];
  for(int i = 0; i < num; i++){
    p[i] = l.p[i];
  }
};

void Polilinea::Aniade(const Punto &p1){
  Punto* sobre = new Punto[num + 1];
  for(int i = 0; i < num; i++){
    sobre[i] = Punto(p[i]);
  }
  sobre[num] = Punto(p1);
  num++;
  delete[] p;
  p = sobre;
};

void Polilinea::Mostrar(){
  for(int i = 0; i < num; i++){
    cout << "(x): " << p[i].getX() << " (y): " << p[i].getY() << endl;
  }
};
