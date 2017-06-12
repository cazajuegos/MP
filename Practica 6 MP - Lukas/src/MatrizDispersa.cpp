#include<iostream>
#include "MatrizDispersa.h"
using namespace std;

Valor::Valor(){
  fila    = 0;
  columna = 0;
  valor   = 0.0;
};
Valor::Valor(const Valor&c){
  fila    = c.fila;
  columna = c.columna;
  valor   = c.valor;
};
Valor::Valor(int c, int f, double v){
  fila    = f;
  columna = c;
  valor   = v;
};
int Valor::getFila() const{ return fila; };
int Valor::getColumna() const{ return columna; };
double Valor::getValor() const{ return valor; };

/* Constructor/Destructor */
MatrizDispersa::MatrizDispersa():nfilas(0), ncolumnas(0){
  valores = new Valor[0];
  numerovalores = 0;
};

/* Razones por la cual no he realizado este apartado:
Como se puede ver no se sabe el tamaño  de la matriz y por tanto no sabemos
el límite del bucle.
MatrizDispersa::MatrizDispersa(int* fl, int* cl, double *vl){

}
*/

MatrizDispersa::MatrizDispersa(const MatrizDispersa& n){
  copia(n);
};

MatrizDispersa::~MatrizDispersa(){
  delete[] valores;
};

Valor* MatrizDispersa::get(int i) const{ return &valores[i]; };

void MatrizDispersa::copia(const MatrizDispersa& n){
  nfilas        = n.nfilas;
  ncolumnas     = n.ncolumnas;
  numerovalores = n.numerovalores;
  valores = new Valor[numerovalores];
  for(int i = 0; i < numerovalores; i++){
    valores[i] = *n.get(i);
  }
};

/* Overload */
MatrizDispersa& MatrizDispersa::operator =(const MatrizDispersa &n){
  if(this != &n){
    copia(n);
  }
  return *this;
};

/* Main */
void MatrizDispersa::show() const{
  int k = 0, li = 0;
  while(k  < numerovalores){
    Valor* xm = get(k);
    int id = ((xm->getColumna()) + (xm->getFila()) * ncolumnas);
    for(int i = li + 1; i < id + 1; i++){
      cout << "0 ";
      if(i % ncolumnas == 0){
        cout << endl;
      }
    }
    cout << xm->getValor() << " ";
    if(xm->getColumna() == (ncolumnas-1)){
      cout << endl;
    }

    li = id + 1;
    k++;
  }
  for(int i = li + 1; i < nfilas * ncolumnas + 1; i++){
    cout << "0 ";
    if(i % ncolumnas == 0){
        cout << endl;
    }
  }
};

void MatrizDispersa::create(){
  int nmb, size = 0, k = 0;
  cout << "Introduzca el numero de columnas: ";
  cin >> nmb;
  ncolumnas = nmb;
  cout << "Introduzca el numero de filas: ";
  cin >> nmb;
  nfilas = nmb;
  cout << "Rellene la matriz: " << endl;
  double values[nfilas][ncolumnas];
  for(int j = 0; j < nfilas; j++){
    for(int i = 0; i < ncolumnas; i++){
      double vl;
      cout << "Introduzca el valor ("<< i << ", " << j << "): ";
      cin >> vl;
      values[j][i] = vl;
      size++;
    }
  }
  valores = new Valor[size];
  for(int j = 0; j < nfilas; j++){
    for(int i = 0; i < ncolumnas; i++){
      if(values[j][i] != 0.0){
        Valor* val = new Valor(i, j, values[j][i]);
        valores[k++] = *val;
      }
    }
  }
  numerovalores = k;
};
