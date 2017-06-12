/*EJERCICIO 9
Escriba la funci�n longitud_cadena, que
devuelva un entero cuyo valor indica la longitud de la cadena: el n�mero de caracteres desde
el inicio hasta el car�cter nulo (no inclu�do). */

#include <iostream>

using namespace std;

int longitud_cadena(const char *cadena){
	const char *p;
	for(p=cadena; *p != '\0'; p++);
	return(p-cadena);
}

int main(){
	const int TOPE = 100;
	char cad[TOPE];
	int longitud;

	cout << "Introduzca una cadena: ";
	cin.getline(cad, TOPE);

	longitud=longitud_cadena(cad);

	cout << "La longitud de la cadena es: " << longitud << endl;


}
