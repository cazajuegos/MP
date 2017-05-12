#include <iostream>
#include <ctime>
#include <cstdlib>
#include "funcionesptr.h"

using namespace std;

int PosMayor(const int *pv, int izda, int dcha){
	int mayor = *pv;
	for (int i = izda; i < dcha; i++){
		if (mayor < *(pv + i)){
			mayor = *(pv + i);
		}
	}
	return mayor;
}

void Rellena(int *cad, int total){
	time_t t;
	srand ((int) time(&t));

	for(int i = 0; i < total; i++){
  		*(cad + i) = (rand() % NUM_VALORES) + MIN;
	}
}

void Rellena_Asigna(int *cad, int **vec, int total){
	time_t t;
	srand ((int) time(&t));

	for(int i = 0; i < total; i++){
  		*(cad + i) = (rand() % NUM_VALORES) + MIN;
		*(vec + i) = cad + i;
	}
}

void Mostrar(const int *cadena, int total){
	for(int i = 0; i < total; i++){
		cout << *(cadena + i) << " ";
	}
	cout << endl;
}

void MostrarPtr(int **ptr, int inicio, int fin){
	for(int i = inicio; i < fin; i++){
		cout << **(ptr + i) << " ";
	}
	cout << endl;
}

void Ordena(int *vec, int **ptr, int izda, int dcha){
	for(int i = izda; i < dcha-1; i++){
		int menor = i;
		for(int j = i+1; j < dcha; j++){
			if(**(ptr + j) < **(ptr + menor)){
				menor = j;
			}
		}
		int *aux = *(ptr + menor);
		*(ptr + menor) = *(ptr + i);
		*(ptr + i) = aux;
	}
}
