/*EJERCICIO 16
Escribir una funcion que recibe un vector de numeros enteros y dos valores enteros que indican las posiciones de los extremos de un intervalo sobre ese vector,
y devuelve un puntero al elemento mayor dentro de ese intervalo.La funcion tendra como prototipo:
int * PosMayor (int *pv, int izda, int dcha);
donde pv contiene la direccion de memoria de una casilla del vector e izda y dcha son los extremos del intervalo entre los que se realiza la busqueda del elemento
mayor. Considere la siguiente declaracon:
const int TOPE = 100;
int vector [TOPE];
Escriba un programa que rellene aleatoriamente el vector (completamente, o una parte) y que calcule el mayor valor entre dos posiciones:
a) Si el programa se ejecuta sin argumentos,se rellenara completamente(TOPE casillas) y se calcular el mayor valor de todo vector(entre las casillas 0 y TOPE-1).
b) Si el programa se ejecuta con un argumento (n), se rellenaran n casillas, y calcular el mayor valor entre ellas (entre las casillas 0 y n-1).
c) Si el programa se ejecuta con dos argumentos (n y d), se rellenaran casillas, y calcular el mayor valor entre las casillas 0 y d.
d) Si el programa se ejecuta con tres argumentos (n, i y d), se rellenaran n casillas, y calcular el mayor valor entre las casillas i y d.
e) Si el programa se ejecuta con m�s de tres argumentos, muestra un mensaje de error y no hace nada mas.*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "funcionesptr.h"

using namespace std;

int main(int argc, char *argv[]){
	const int TOPE = 100;
	int cad[TOPE];
	int *pt = cad;
	int total = TOPE, inicio = 0, fin = TOPE;

	if(argc == 2){
		total = fin = atoi( *(argv + 1) );
	}else if(argc == 3){
		total = atoi( *(argv + 1) );
		fin	= atoi( *(argv + 2) );
	}else if(argc == 4){
		total = atoi( *(argv + 1) );
		inicio = atoi( *(argv + 2) );
		fin = atoi( *(argv + 3) );
	}else if(argc > 4){
		cout << "Error en los argumentos.\n";
		return 0;
	}

	cout << "El vector se relleno con " << total << " elementos\n";
	Rellena(cad, total);
	Mostrar(cad, total);


	int mayor = PosMayor(cad, inicio, fin);
	cout << "\nEl mayor numero entre (" << inicio << ", " << fin << ") es el: " << mayor << endl;

	return 0;
}
