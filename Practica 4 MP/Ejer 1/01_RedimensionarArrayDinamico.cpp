#include <iostream>
#include <cstdlib>

using namespace std;

enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};

int * Redimensiona (int * p, TipoRedimension Redimensiona, int & cap){
  int TAM_BLOQUES, delta = 0;

  if(Redimensiona == DeUnoEnUno){
    delta = 1;
  }else if(Redimensiona == EnBloques){
    cout << "Introduzca el tamanio de los bloques: ";
    cin >> TAM_BLOQUES;
    delta = TAM_BLOQUES;
  }else{  //Caso Duplicando
    delta = cap;
  }
  int *red = new int[cap + delta];
  for(int i = 0; i < cap; i++){
    *(red + i) = *(p + i);
  }
  cap += delta;
  return (p = red);
}

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
  // cout << "Introduzca el TAM del vector: ";
  // cin >> TAM;
  
  TAM=0;
  int *vec = new int[TAM];

  system("/usr/bin/clear");

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

  cout << endl;

  for(int i = 0; i < TAM -1; i++){
    cout << vec[i] << " ";
  }

  delete[] vec;

  return 0;
}
