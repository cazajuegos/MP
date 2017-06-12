/*EJERCICIO 11
Escriba la funci�n comparar_cadenas,
que devuelve un valor entero que se interpretar� como sigue: si es negativo, la primera cadena
es m�s �peque�a�; si es positivo, ser� m�s �grande�; y si es cero, las dos cadenas son
�iguales�. */

// '\0' es en ASCII el 0

#include <iostream>
using namespace std;

int compara_cadenas(const char *cad1, const char *cad2){
	const char *p1, *p2;

	for(p1=cad1; *p1 != '\0'; p1++);
	for(p2=cad2; *p2 != '\0'; p2++);

	return((p1-cad1)-(p2-cad2));
}


int main(){
	int TOPE = 100;
	char cad1[TOPE], cad2[TOPE];
	int resultado;


	cout << "Introduzca la primera cadena: ";
	cin.getline(cad1, TOPE);
	cout << "Introduzca la primera cadena: ";
	cin.getline(cad2, TOPE);

	resultado=compara_cadenas(cad1,cad2);

	if(resultado==0)
	cout << "Las cadenas tienen el mismo tamano" << endl;
	else if(resultado >0)
	cout << "Cadena 1 mayor que cadena 2" << endl;
	else
	cout << "Cadena 1 menor que cadena 2" << endl;


}
