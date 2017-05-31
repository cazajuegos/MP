#include<iostream>
#include "Menu.h"
using namespace std;

/* Constructor/Destructor */
Menu::Menu(){
  nopciones = 0;
};

Menu::Menu(const Menu& m){
  copy(m);
};

Menu::~Menu(){
  delete[] titulo;
  deleteOpciones();
}

/* get/set */
int Menu::getTotal() const{ return nopciones; };
void Menu::setOpcion(char* opcion){
  char** nupciones = new char*[nopciones + 1];
  int k;
  for(int i = 0; i < nopciones; i++){
    k = 0;
    while(opciones[i][k] != '\0'){ k++; };
    nupciones[i] = new char[k + 1];
    for(int j = 0; j <= k; j++){ nupciones[i][j] = opciones[i][j]; };
  }

  k = 0;
  while(opcion[k] != '\0'){ k++; };
  nupciones[nopciones] = new char[k + 1];
  for(int j = 0; j <= k; j++){ nupciones[nopciones][j] = opcion[j]; };
  deleteOpciones();
  opciones = nupciones;
  nopciones++;
};

void Menu::setTitle(char* title){
  int k = 0;
  while(title[k] != '\0'){ k++; };
  titulo = new char[k];
  for(int i = 0; i <= k; i++){
    titulo[i] = title[i];
  }
};

void Menu::deleteOpciones(){
  for(int i = 0; i < nopciones; i++){
    delete[] opciones[i];
  }
  delete[] opciones;
}

/* Overload */
Menu& Menu::operator =(const Menu &n){
  if(this != &n){
    copy(n);
  }
  return *this;
};

void Menu::copy(const Menu& o){
  nopciones = o.nopciones;
  int k = 0;
  while(o.titulo[k] != '\0'){ k++; };
  titulo = new char[k + 1];
  for(int i = 0; i <= k; i++){ titulo[i] = o.titulo[i]; };
  opciones = new char*[nopciones];
  for(int i = 0; i < nopciones; i++){
    k = 0;
    while(o.opciones[i][k] != '\0'){ k++; };
    opciones[i] = new char[k + 1];
    for(int j = 0; j <= k; j++){ opciones[i][j] = o.opciones[i][j]; };
  }
};

void Menu::show() const{
  cout << titulo << "(" << nopciones << "):" << endl;
  for(int i = 0; i < nopciones; i++){
    cout << (char)('a' + i) << ") " << opciones[i] << endl;
  }
};
