//EJERCICIO 7 
/*Escriba un trozo de código que lea una cadena y localice la posición del primer carácter espacio
(’ ’) en una cadena de caracteres “clásica”. El programa debe indicar su posición (0:
primer carácter, 1: segundo carácter, etc.).*/

#include <iostream>
using namespace std;



int main(void){
	const int TOPE = 100;
	char cad[TOPE];
	
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

