#include<iostream>
#include "Lista.h"
using namespace std;

Celda::Celda(){
  info  = 0;
  sig   = NULL;
};

Celda::Celda(const Celda& c){
  info  = c.info;
  sig   = c.sig;
};

Celda::Celda(double inf, Celda *n1){
  info  = inf;
  sig   = n1;
};

Celda* Celda::getSiguiente() const{
  return sig;
};

void Celda::setSiguiente(Celda *n){
  sig = n;
};

void Celda::show() const{
  cout << "El valor es: " << info << endl;
}

/* Constructor/Destructor */
Lista::Lista(){};

Lista::Lista(const Lista&n){
  Celda* sig = n.getPrimero();
  Celda* cp = new Celda(*sig);

  setPrimero(cp);
  while(sig->getSiguiente() != NULL){
    sig = sig->getSiguiente();
    cp->setSiguiente(new Celda(*sig));
    cp = cp->getSiguiente();
  }
};

Lista::~Lista(){
  Celda* sig = primero, *mx;
  while(sig->getSiguiente() != NULL){
    mx = sig->getSiguiente();
    delete sig;
    sig = mx;
  }
}

/* get/set */
Celda* Lista::getPrimero() const{ return primero; };
void Lista::setPrimero(Celda* n){ primero = n; };

/* Overload */
Lista Lista::operator +(const Lista &n){
  Lista sumadas(*this);
  Celda *sig = sumadas.getPrimero();
  while(sig->getSiguiente() != NULL){
    sig = sig->getSiguiente();
  }
  sig->setSiguiente(n.getPrimero());
  return sumadas;
};

Lista& Lista::operator =(const Lista &n){
  if(this != &n){
    Celda* sig = n.getPrimero();
    Celda* cp = new Celda(*sig);

    setPrimero(cp);
    while(sig->getSiguiente() != NULL){
      sig = sig->getSiguiente();
      cp->setSiguiente(new Celda(*sig));
      cp = cp->getSiguiente();
    }
  }
  return *this;
};

void Lista::operator [](const int n){
  int k = 1;
  Celda* nxt = primero;
  Celda *aux = nxt;
  if(n != 0){
    while(k < n && nxt->getSiguiente()->getSiguiente() != NULL){
      nxt = nxt->getSiguiente();
      k++;
    }
    aux = nxt->getSiguiente();
    if(nxt->getSiguiente()->getSiguiente() != NULL){
      nxt->setSiguiente(nxt->getSiguiente()->getSiguiente());
    }else{
      nxt->setSiguiente(NULL);
    }
  }else{
    setPrimero(nxt->getSiguiente() == NULL ? NULL : nxt->getSiguiente());
  }
  delete aux;
};

void Lista::show() const{
  Celda *sig = primero;
  sig->show();
  while(sig->getSiguiente() != NULL){
    sig = sig->getSiguiente();
    sig->show();
  }
}

void Lista::create(){
  int term = 0, n = 0;
  double info = 0;
  Celda *last = NULL;
  cout << "->>Creemos la siguiente lista<<- " << endl;
  do{
    cout << "Introuduzca el elemento " << n++ << " de la lista: ";
    cin >> info;
    Celda* aux = new Celda(info, NULL);
    if(last != NULL){
      last->setSiguiente(aux);
    }else{
      setPrimero(aux);
    }
    last = aux;
    cout << "Introduzca -1 para terminar: ";
    cin >> term;
  }while(term != -1);
}
