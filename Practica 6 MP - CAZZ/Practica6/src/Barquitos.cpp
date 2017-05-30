#include <iostream>
#include <cstdlib>
#include "Barquitos.h"

using namespace std;

Barquitos::Barquitos(int _filas, int _columnas):filas(_filas), columnas(_columnas){
  tablero = new int *[filas];

  for(int i = 0; i < filas; i++){
    tablero[i] = new int[columnas];
    for(int j = 0; j < columnas; j++){
      tablero[i][j] = 9;
    }
  }
};

Barquitos::~Barquitos(){
  for(int i = 0; i < filas; i++){
    delete [] tablero[i];
  }
  delete [] tablero;
};

Barquitos::Barquitos(const Barquitos &b){
  filas = b.filas;
  columnas = b.columnas;
  tablero = new int *[filas];
  for(int i = 0; i < filas; i++){
    tablero[i] = new int[columnas];
  }
};

void Barquitos::Muestra(){
  cout << "    ";

  for(int i = 1; i <= columnas; i++){
    if(i < 10){
    cout << i << "  ";
  }
    else
    cout << i << " ";
  }

  cout << endl;
  for(int i = 0; i < filas; i++){
      cout << "|" << (char)('A' + i) << "|";
    for(int j = 0; j < columnas; j++){
      if(tablero[i][j] == 9){
        cout << " ~ ";
      }else if(tablero[i][j] == -9){
        cout << " o ";
      }else if(tablero[i][j] < 0 && tablero[i][j] != -9){
        cout << " * ";
      }else{
        cout << " " <<tablero[i][j] << " ";
      }
    }
    cout << "" << endl;
  }
};

bool Barquitos::Limites(int a, int b){
  if(a >= 0 && a <= filas && b >= 0 && b <= columnas){
    return true;
  }
  else{
    return false;
  }
};

void Barquitos::Poner_Barcos(int x, int y, int tam, char posicion){
  bool agua = true;

    if(Limites(x, y)){

      if(toupper(posicion) == 'H' && (tam + x) < columnas){
        for(int i = x; i < (tam + x) && agua; i++){
          if(tablero[y][i] != 9){
            agua = false;
          }if(!agua){
            cout << "¡Posicion invalida, barco existente!\n" << endl;
          }
        }
        for(int i = x; i < (tam + x) && agua; i++){
          tablero[y][i] = tam;
        }
      }

      else if(toupper(posicion) == 'V' && (tam + y) < filas){
        for(int j  = y; j < (tam + y) && agua; j++){
          if(tablero[j][x] != 9){
            agua = false;
          }else if(!agua){
            cerr << "¡Posicion invalida, barco existente!\n" << endl;
          }
        }
        for(int j = y; j < (tam + y) && agua; j++){
          tablero[j][x] = tam;
        }
      }
    }
};

void Barquitos::Dispara(){
  int x, z;
  char y, respuesta;

  cout << "\n¿Desea disparar(Y/N)? ";
  cin >> respuesta;
  while(toupper(respuesta) == 'Y'){
    cout << "Cordenadas para disparar: ";
    cin >> x >> y;
    z = y - 'A';
    x--;

    if(tablero[z][x] > 0 && tablero[z][x] != 9){
      cout << "Le hemos dado\n" << endl;
      tablero[z][x] = -tablero[z][x];
    }else if(tablero[x][z] == 9){
      cout << "Agua\n"<< endl;
      tablero[z][x] = -9;
    }else{
      cerr << "Ya hemos disparado en esa posicion\n" << endl;
    }

    Muestra();

    cout << "\n¿Desea disparar(Y/N)? ";
    cin >> respuesta;
  }
};

void Barquitos::Limpiar(){
  system("/usr/bin/clear");
};
