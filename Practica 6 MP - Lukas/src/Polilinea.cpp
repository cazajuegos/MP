#include<iostream>
#include "Polilinea.h"
using namespace std;

Punto::Punto(){
    x = 0;
    y = 0;
};

Punto::Punto(int i, int j){
    x = i;
    y = j;
};

Punto::Punto(const Punto&n){
  x = n.getX();
  y = n.getY();
};

bool Punto::operator ==(const Punto&n) const{
  return ((x == n.getX()) && (y == n.getY()));
}

int Punto::getX() const{ return x; };
int Punto::getY() const{ return y; };

void Punto::show(){ cout << "(" << x << "," << y << ")"; };


/* Constructor/Destructor */
Polilinea::Polilinea(){
  total = 0;
  puntos = new Punto[0];
};
Polilinea::Polilinea(const Polilinea&n){
  total = n.getTotal();
  puntos = new Punto[total];
  for(int i = 0; i < total; i++){
    puntos[i] = Punto(n.getPunto(i));
  }
};
Polilinea::~Polilinea(){
  delete[] puntos;
};

/* get/set */
int Polilinea::getTotal() const{ return total; };
Punto Polilinea::getPunto(int i) const{ return puntos[i]; };

void Polilinea::setPunto(const Punto&punto){
  bool canput = true;
  for(int i = 0; i < total && canput; i++){
    if(punto == getPunto(i)) canput = false;
  }
  if(canput){
    Punto *newpuntos = new Punto[total + 1];
    for(int i = 0; i < total; i++){
      newpuntos[i] = Punto(getPunto(i));
    }
    newpuntos[total] = Punto(punto);
    total++;
    delete[] puntos;
    puntos = newpuntos;
  }
};

/* overload */
Polilinea& Polilinea::operator =(const Polilinea &p){
  if(this != &p){
    total = p.getTotal();
    puntos = new Punto[total];
    for(int i = 0; i < total; i++){
      puntos[i] = Punto(p.getPunto(i));
    }
  }
  return *this;
};

/* main */
void Polilinea::show(){
  cout << "Encontramos los siguientes pares de puntos: " << endl;
  for(int i = 0; i < total - 1; i++){
    getPunto(i).show();
    cout << ", ";
  }
  getPunto(total - 1).show();
};
