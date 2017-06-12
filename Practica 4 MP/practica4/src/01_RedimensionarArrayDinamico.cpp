#include <iostream>
#include <cstdlib>
#include "utilidades.h"

using namespace std;

int main(int argc, char const *argv[]) {
  TipoRedimension Redimension;
  const char *CENTINELA = "FIN";
  int TAM, valor;

  if(argc == 1){
    Redimension = DeUnoEnUno;
  }else if(argc == 2){
    switch(atoi( *(argv + 1) )){
        case 1: Redimension = DeUnoEnUno; break;
        case 2: Redimension = EnBloques;  break;
        case 3: Redimension = Duplicando; break;
        default: cerr << "ERROR TIPO DE REDIMENSION" << endl;
    }
  }else{
    cerr << "ERROR DE ARGUMENTOS" << endl;
    exit(0);
  }

  //Creo Vector Dinamico
  cout << "Introduzca el TAM del vector: ";
  cin >> TAM;

  int *vec = new int[TAM];

  Limpiar_Ventana();

  for(int i = 0; valor != atoi(CENTINELA); i++){
    if(i >= TAM){
      vec = Redimensiona(vec, Redimension, TAM);
    }
    cout << "Introduzca el valor (" << i << "): ";
    cin >> valor;
    *(vec + i) = valor;
    cout << "VECTOR: " << vec << "\nVECTOR + i: " << (vec + i) << "\nVECTOR[TAM]: " << &vec[TAM] << endl;
    cout <<  "Dentro vec actual: " << *(vec + i) << endl;
    cout << "TAM: " << TAM << endl << endl;
  }

  Limpiar_Ventana();

  Mostrar(vec, TAM);

  cout << endl;

  delete[] vec;

  return 0;
}
