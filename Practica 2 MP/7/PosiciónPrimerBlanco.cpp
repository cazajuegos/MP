//EJERCICIO 7
/*Escriba un trozo de c�digo que lea una cadena y localice la posici�n del primer car�cter espacio
(� �) en una cadena de caracteres �cl�sica�. El programa debe indicar su posici�n (0:
primer car�cter, 1: segundo car�cter, etc.).*/

#include <iostream>

using namespace std;

int main(void){
	const int TOPE = 100;
	char cad[TOPE];
	int cad1[TOPE];

	cout << "Introduzca una cadena: ";
	cin.getline(cad, TOPE);

	char *p = cad;

	while((*p != ' ')&&(*p != '\0')) p++;

	if(*p == '\0')
		cout << "No hay espacios" << endl;
	else
		cout << "Espacio en: " << p-cad << endl;

	return 0;
}
