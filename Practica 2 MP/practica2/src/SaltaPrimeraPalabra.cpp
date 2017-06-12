//EJERICIO 8.
/*Escriba un trozo de código que lea una
cadena y la imprima pero saltándose la primera palabra, evitando escribirla carácter a carácter.
Considere que puede haber una o más palabras, y si hay más de una palabra, están separadas
por espacios en blanco.*/

#include <iostream>
using namespace std;



int main(void){
	const int TOPE = 100;
	char cad[TOPE];
	
	cout << "Introduzca una cadena: ";
	cin.getline(cad, TOPE);
	
	char *p = cad;
	
	while((*p != ' ')&&(*p != '\0')) p++;

	
	if (*p != '\0')
		cout << ++p << endl; //Para que no salga espacio en blanco al princpio
	else
		cout << "NO HAY ESPACIOS EN BLANCO" << endl;

	return 0;
}

