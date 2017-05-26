#include<iostream>
using namespace std;

const int TAM_BLOQUES = 2;
enum TipodeRedimension{UnoAUno, EnBloques, Duplicando};

int *Redimensiona(int *p, TipodeRedimension tipo, int& capacidad){
  int redimension = 0;
  int *redimensionado;

  switch (tipo) {
    case UnoAUno    : redimension = 1;            break;
    case EnBloques  : redimension = TAM_BLOQUES;  break;
    case Duplicando : redimension = capacidad;    break;
  }

  if(redimension > 0){
    redimensionado = new int[capacidad + redimension];
    for(int i = 0; i < capacidad; i++){
      *(redimensionado + i) = *(p + i);
    }
    capacidad += redimension;
    delete[] p;
  }else{
    redimensionado = p;
  }
  return redimensionado;
}

void Mostrar(int *valores, int total){
  for(int i = 0; i < total; i++){
    cout << *(valores + i) << " ";
  }
}

int main(int total, char **str){
  const int TERMINATOR = -1;
  int capacity = TAM_BLOQUES, used = 0;
  int *numbers = new int[capacity];
  TipodeRedimension tipo = UnoAUno;
  if(total == 2){
    int num = str[1][0] - '0';
    switch (num) {
      case 1: tipo = UnoAUno;
      case 2: tipo = EnBloques;
      case 3: tipo = Duplicando;
    }
  }

  int newNumber = 0;
  cin >> newNumber;
  while(newNumber != TERMINATOR){
    if(used >= capacity){
      numbers = Redimensiona(numbers, tipo, capacity);
    }
    *(numbers + used) = newNumber;
    used++;
    cin >> newNumber;
  }
  Mostrar(numbers, used);
  delete[] numbers;
}
