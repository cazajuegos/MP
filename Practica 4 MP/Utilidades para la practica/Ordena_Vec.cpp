#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN = 1, MAX=25, NUM_VALORES = MAX-MIN+1;

void Rellena(int *cad, int total){
	time_t t;
	srand ((int) time(&t));

	for(int i = 0; i < total; i++){
  		*(cad + i) = (rand() % NUM_VALORES) + MIN;
	}
}

bool ComprobarOrdenAscendente(int a, int b){
  return(a < b);
}

bool ComprobarOrdenDescendente(int a, int b){
  return(a > b);
}

void Cambiar(int *const ptr1, int *const ptr2){
  int aux = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = aux;
}

void Ordenar(int *vec, const int total, bool (*comparacion)(int,int)){
  int indice;

  for(int i = 0; i < total -1; i++){
    indice = i;
    for(int j = i + 1; j < total; j++){
      if(!(*comparacion)(vec[indice],vec[j])){
        indice = j;
      }
    }
    Cambiar(&vec[indice], &vec[i]);
  }
}

void Mostrar(const int *vec, int total){
  for(int i = 0; i < total; i++){
    cout << vec[i] << " ";
  }
  cout << endl;
}

void Elimina_Repetidos(int *vec, int &TAM){
  for(int i = 0; i < TAM; i++){
    for(int j = i + 1; j < TAM; j++){
      if(vec[i] == vec[j]){
        for(int h = j; h < TAM; h++){
          vec[h] = vec[h+1];
        }
        TAM --;
        j --;
      }
    }
  }
}

void Introducir_Datos(int *vec, const int TAM){
	for(int i = 0; i < TAM; i++){
		cout << i+1 << ". Valor: ";
		cin >> *(vec + i);
	}
}

void Limpiar() {
	system("/usr/bin/clear");
}


int main(int argc, char const *argv[]) {
  int TAM;
	char respuesta;

  cout << "Introduzca el TAM: ";
  cin >> TAM;

  int *vec = new int[TAM];

	Limpiar();

	cout << "ALEATORIAMENTE: A\nMANUALMENTE: M\n";
	cin >> respuesta;

	Limpiar();

	if(respuesta == 'A'){
  Rellena(vec, TAM);
	cout << "VECTOR RELLENO CON NUMEROS ALEATORIAMENTE: " << endl;
  Mostrar(vec, TAM);
}else if(respuesta == 'M'){
	cout << "VECTOR RELLENO MANUALMENTE: " << endl;
	Introducir_Datos(vec, TAM);
	Mostrar(vec, TAM);
	}

  cout << "\nVECTOR ORDENADO DESCENDENTEMENTE: " << endl;
  Ordenar(vec, TAM, ComprobarOrdenDescendente);
  Mostrar(vec, TAM);

  cout << "\nVECTOR ORDENADO ASCENDENTEMENTE: " << endl;
  Ordenar(vec, TAM, ComprobarOrdenAscendente);
  Mostrar(vec, TAM);

  cout << "\nELIMINA REPETIDOS: " << endl;
  Elimina_Repetidos(vec, TAM);
  Mostrar(vec, TAM);

  delete[] vec;

  return 0;
}
