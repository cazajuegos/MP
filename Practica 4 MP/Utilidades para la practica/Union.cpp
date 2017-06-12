//REALICE LA UNION DE DOS CONJUNTOS DE FORMA DINAMICA
#include <iostream>
#include <cstdlib>

using namespace std;

bool ExisteEn(const int *vec, int TAM, int elm){
  bool existe = false;
  for(int j = 0; j < TAM; j++)
    if(elm == *(vec + j)) existe = true;
  return existe;
}

int * Redimensiona (int *vec, int &TAM){
  int *red, delta;
  red = new int [++TAM];
  for(int i = 0; i < TAM - 1; i++){
    *(red + i) = *(vec + i);
  }
  delete[] vec;
  vec = red;
  return red;
}

void Pedir_Valores (int *vec, int &TAM){
  const int CENTINELA = -1;
  int valor, i = 0;

  cout << "Inroduzca el valor (" << i << "): ";
  cin >> valor;
  while(valor != CENTINELA){
    if(!ExisteEn(vec, TAM, valor)){
      if(i >= TAM){
        Redimensiona(vec, TAM);
      }

      *(vec + i) = valor;
      i++;
    }
    cout << "Inroduzca el valor (" << i << "): ";
    cin >> valor;
  }
}

void Muestra (const int *vec, int TAM){
  for(int i = 0; i < TAM; i++){
    cout << *(vec + i) << " ";
  }
  cout << endl;
}

int *Union_vec (const int * vec, const int *vec1, const int TAM, const int TAM1, int&tamanio){
  int tm = TAM;
  int *un = new int[tm + 1];
  for(int i = 0; i < TAM; i++){
    *(un + i) = *(vec + i);
  }

  for(int i = 0; i < TAM1; i++){
    int elm = *(vec1 + i);

    if(!ExisteEn(vec, TAM, elm)){
      Redimensiona(un, tm);
      *(un + TAM + i - 1) = elm;
    }
  }
  tamanio = tm;
  return un;
}

int main(int argc, char const *argv[]) {
  int TAM = 1, TAM1 = 1;
  int *vec = new int[TAM];
  int *vec1 = new int[TAM1];
  int TAM_UNION;

  cout << "VECTOR 1" << endl;
  Pedir_Valores(vec, TAM);
  cout << "VECTOR 2" << endl;
  Pedir_Valores(vec1, TAM1);

  int tam = 0;
  int *un = Union_vec(vec, vec1, TAM, TAM1, tam);
  cout << "\nUnion Vector: " << endl;
  Muestra(un, tam);

  return 0;
}
