/*EJERCICIO 18.
-calcular la nota media final de cada alumno, 4 calif parciales, sumen 100.

Paso 1. LEER , los cuatro pesos que se asignan a las calificaciones
parciales (valores reales que indican porcentajes). Una vez leidos comprobar que efectivamente
suman 100% y en el caso de que no lo fueran, se detendra la ejecucion del
programa.

Paso 2. Leer para cada alumno: apellidos, nombre, y las cuatro calificaciones. Cada uno de los
seis datos asociados a cada alumno se lee por separado. Los datos se almacenan en
memoria usando un array.

La lectura finaliza cuando se introduce el caracter * en la lectura de los apellidos de un
alumno.

Paso 3. Calcular (y guardar) la nota media de cada alumno. Usar un array para guardar las calificaciones
medias.

Paso 4. Finalmente, mostrar un listado en el que se detalla, para cada alumno: apellidos y nombre
y nota media.

Para la resolucion de este ejercicio proponemos usar el tipo RegAlumno:
struct RegAlumno {
double notas[NUM_NOTAS];
char apellido_nombre[TAM_NOMBRE]; // Cadena "clasica"
};

(NUM_NOTAS ser 4 segun el enunciadpo, y TAM_NOMBRE ser, por ejemplo, 80).
y las siguientes estructuras de datos para almanecenar y procesar los datos:

-pesos: array de exactamente NUM_NOTAS valores double: son los pesos de las calificaciones
de los alumnos.

- alumnos: array de TAMANIO casillas (100, segun el enunciado) de tipo RegAlumno.
Se ocuparan num_alumnos casillas (0 <= num_alumnos <= TAMANIO)

-calificacion_media: array de TAMANIO valores double: las calificaciones medias
de los alumnos. Se ocuparan num_alumnos casillas, el mismo n�mero que en el
array alumnos: son arrays paralelos. */

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "funcionescalif.h"

using namespace std;

int main(){
	double calificacion_media[TAM];
	double pesos[NUM_NOTAS];
	int n_alum;

	Ponderaciones(pesos);

	system("/usr/bin/clear");

	cout << "Digite el numero de alumnos: ";
	cin >> n_alum;

	RellenaDatos(n_alum);
	NotaMedia(calificacion_media, pesos, n_alum);
	ImprimirDatos(calificacion_media, n_alum);
}
