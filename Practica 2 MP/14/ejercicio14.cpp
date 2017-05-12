/*EJERCICIO 14
Escriba una función a la que le damos una cadena de caracteres, una posición de inicio p y
una longitud l sobre esta cadena. Queremos obtener una subcadena de ésta, que comienza
en p y que tiene longitud l .
Notas:
• Si la longitud es demasiado grande (se sale de la cadena original), se devolverá una
cadena de menor tamaño (la que empieza en p y llega hasta el final de la cadena).
• No se puede usar el operador
punteros. */

#include <iostream>
using namespace std;

char subcadena(char *cad1, const char *cad2, int inicio, int longitud){

	for(const char *p2=cad2+inicio; longitud != 0; longitud--){
		*cad1=*p2;
		cad1++;
		p2++;
	}

	return *cad1;
}


int main(){
	const int TOPE = 100;
	int inicio, longitud;
	char cad1[TOPE], cad2[TOPE];

	cout << "Introduzca la cadena: ";
	cin.getline(cad2, TOPE);
	cout << "Indique el incio: ";
	cin >> inicio;
	cout << "Indique la longitud: ";
	cin >> longitud;

	subcadena(cad1, cad2, inicio, longitud);

	cout << "Su nueva subcadena es: \n" << cad1 << endl;



}
