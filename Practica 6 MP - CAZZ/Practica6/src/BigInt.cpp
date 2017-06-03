#include <iostream>
#include <string>
#include <cstdlib>
#include "BigInt.h"

using namespace std;

  BigInt::BigInt(){
    tam = 1;
    numero = new int[tam];
    numero[0] = 0;
  };

  BigInt::BigInt(int tm){
    tam = tm;
    numero = new int[tam];
    for(int i = 0; i < tam; i++){
      numero[i] = 0;
    }
  };

  BigInt::~BigInt(){
    delete [] numero;
  };

  BigInt::BigInt(const BigInt &b){
    tam = b.tam;
    numero = new int [tam];
    for(int i = 0; i < tam; i++){
      numero[i] = b.numero[i];
    }
  };

  void BigInt::Lee_Numero(){
    char num[100];
    cout << "Introduzca el numero: ";
    cin.getline(num, 100);

    tam = 0;
    while(num[tam] != '\0'){
      tam++;
    }
    numero = new int[tam];
    for(int i = 0; i < tam; i++){
      numero[i] = num[tam - 1 - i] - '0';
    }
  };

  void BigInt::Muestra(){
    for(int i= tam-1; i >= 0; i--){
      cout << numero[i];
    }
  };

  BigInt BigInt::Suma(const BigInt &b){
    int acarreo = 0;
    int mayor_tam;

    if(tam > b.tam){
      mayor_tam = tam;
    }else{
      mayor_tam = b.tam;
    }

    int suma[mayor_tam];

    for(int i=0; i < mayor_tam; i++){
      int sm = numero[i] + b.numero[i] + acarreo;
      acarreo = sm / 10;
      suma[i] = sm % 10;
    }
    BigInt numsumado(tam + acarreo);

    for(int i = 0; i < tam; i++){
      numsumado.numero[i] = suma[i];
    }
    numsumado.numero[tam - 1 + acarreo] += acarreo;
    return numsumado;
  };
