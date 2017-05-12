/*EJERCICIO 17
Escriba un programa que haciendo uso de la funcion permita ordenar el vector entre dos
posiciones:
- Si el programa se ejecuta sin argumentos ordenar todo vector.
- Si el programa se ejecuta con dos argumentos, ordenar el vector entre las dos posiciones
dadas.
- En otro caso, muestra un mensaje de error y no hace nada mas.
Nota: Iniciar aleatoriamente el vector vec.
Nota: Modularice la solucion con funciones.*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "funcionesptr.h"

using namespace std;

int main(int argc, char *argv[]){
	const int TOPE = 10;
	int vec [TOPE];
	int * ptr [TOPE];
	int inicio = 0, fin = TOPE;

	if(argc == 3){
		inicio = atoi( *(argv + 1) );
		fin = atoi( *(argv + 2) );
	}
	else if(argc > 2){
		cout << "ERROR DE ARGUMENTOS\n";
	}

	cout << "El vector: " << endl;
	Rellena_Asigna(vec, ptr, TOPE);
	Mostrar(vec, TOPE);

	cout << "El vector puntero ordenando el vector original: " << endl;
	Ordena(vec, ptr, inicio, TOPE);
	MostrarPtr(ptr, inicio, fin);

	return 0;
}
