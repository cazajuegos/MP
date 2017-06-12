//EJERICIO 8.
/*Escriba un trozo de c�digo que lea una
cadena y la imprima pero salt�ndose la primera palabra, evitando escribirla car�cter a car�cter.
Considere que puede haber una o m�s palabras, y si hay m�s de una palabra, est�n separadas
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
		cout << ++p << endl; // ++ -> Para que no salga espacio en blanco al princpio
	else
		cout << "NO HAY ESPACIOS EN BLANCO" << endl;

	return 0;
}
