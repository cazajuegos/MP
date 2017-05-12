#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <limits>
#include "funcionescalif.h"

using namespace std;

struct RegAlumno{
	double notas[NUM_NOTAS];
	char apellido_nombre[TAM_NOMBRE];
}alumnos[TAM];

void NotaMedia(double media[], double pesos[], int n_alumnos){
	double suma=0;

	for(int i=0; i<n_alumnos; i++){
		for(int j=0; j<NUM_NOTAS; j++){
			suma = suma+((alumnos[i].notas[j] * pesos[j]) / 100.0);
		}
	media[i]=suma;
	suma=0;
	}
}

bool Comprobar(double pesos[]){
	bool comprobar = false;
	double suma;
	int i=0;
	while(i < NUM_NOTAS){
		suma += pesos[i];
		i++;
	}
	return (suma == 100);
}

void RellenaDatos(int n_alum){
	for(int i = 0; i < n_alum; i++){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout <<i+1<< ". Digite su nombre y apellidos: ";
		cin.getline(alumnos[i].apellido_nombre, TAM_NOMBRE);
		for(int j=0; j < NUM_NOTAS; j++){
			cout <<j+1<< ". Nota: ";
			cin >> alumnos[i].notas[j];
		}
		system("/usr/bin/clear");
	}
}

void Ponderaciones(double pesos[]){
	cout << "Digite las ponderaciones: \n";
	for(int i = 0; i < NUM_NOTAS; i++){
		cout << i+1 << ". Ponderacion: ";
		cin >> pesos[i];
	}

	if(Comprobar(pesos) == false){
		cout << "Las ponderaciones introducidas no son correctas" << endl;
		exit(0);
	}
	else{
		cout << "Ponderaciones introducidas correctas" << endl;
	}
}

void ImprimirDatos(double media[], int n_alumnos){
	for(int i=0; i<n_alumnos; i++){
		cout << "\n\n***" << i+1. << ".ALUMNO***\n";
		cout << alumnos[i].apellido_nombre << endl;
		for(int j=0; j<NUM_NOTAS; j++){
			cout << j+1. << "Nota: " << alumnos[i].notas[j] << endl;
		}
		cout << "NOTA MEDIA: " << media[i];
	}
	cout << "\n";
}

void Ordena_Calif_Alumnos(double media[], int n_alumnos){
	for(int i = 0; i < n_alumnos-1; i++){
		int menor = i;
		for(int j = i+1; j < n_alumnos; j++){
			if(media[j] < media[menor]){
				menor = j;
			}
		}
		double aux = media[menor];
		media[menor] = media[i];
		media[i] = aux;
		RegAlumno aux2 = alumnos[menor];
		alumnos[menor] = alumnos[i];
		alumnos[i] = aux2;
	}
}

void Muestra_Ponderaciones(double pesos[]){
	cout << "Estas son las ponderaciones:\n";
	for(int i=0; i<NUM_NOTAS; i++){
		cout << i+1 << ".Ponderacion: " << pesos[i] << "\n";
	}
}

void Muestra_Calif(double calificacion_media[], int num_alumnos){
	cout << "Calificaciones medias ordenadas:\n";
	for(int i = 0; i<num_alumnos; i++){
		cout << calificacion_media[i] << "  ";
	}
	cout << "\n";
}

void ImprimirDatos_arg(double calificacion_media[], double inicio_nota, double final_nota, int num_alumnos){
	cout << "\nAlumnos filtrado por las notas: " << inicio_nota << "-" << final_nota << endl;

	for(int i=0; i<num_alumnos; i++){
		if((calificacion_media[i] >= inicio_nota) && (calificacion_media[i] <= final_nota)){
			cout << "Nombre y apellidos: " << alumnos[i].apellido_nombre << endl;
			for (int j=0; j<NUM_NOTAS; j++){
				cout << j+1 << ".Nota: " << alumnos[i].notas[j] << endl;
			}
			cout << "NOTA MEDIA: " << calificacion_media[i] << endl;
		}
	}
}
