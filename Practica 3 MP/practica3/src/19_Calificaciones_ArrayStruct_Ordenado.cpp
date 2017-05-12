/*EJERCICIO 19
Modularizar cn funciones el ejercicio 18. */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <cstdlib>
#include "funcionescalif.h"

using namespace std;

int main(int argc, char *argv[]){
	double calificacion_media[TAM];
	double pesos[NUM_NOTAS];
	int n_alum;

	Ponderaciones(pesos);

	system("/usr/bin/clear");

	Muestra_Ponderaciones(pesos);

	cout << "\nDigite el numero de alumnos: ";
	cin >> n_alum;

	system("/usr/bin/clear");

	RellenaDatos(n_alum);
	NotaMedia(calificacion_media, pesos, n_alum);
	Ordena_Calif_Alumnos(calificacion_media, n_alum);
	Muestra_Calif(calificacion_media, n_alum);

	if(argc == 3){
		double inicio_nota = atoi ( *(argv + 1) );
		double final_nota = atoi ( *(argv + 2) );
		ImprimirDatos_arg(calificacion_media, inicio_nota, final_nota, n_alum);
	}
	else if(argc == 1){
			ImprimirDatos(calificacion_media, n_alum);
	}
	else{
		cout << "Error de argumentos" << endl;
	}
}
