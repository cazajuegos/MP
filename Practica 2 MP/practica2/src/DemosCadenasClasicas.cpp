#include <iostream>
#include <cstring>
#include "miCadenaClasica.h"

using namespace std;

int main(){
	const int TOPE = 100;
	char cad1[TOPE];
	char cad2[TOPE];

//EJERCICIO 9
	int longitud;

	cout << "LONGITUD CADENA" << endl;

	cout << "Introduzca una cadena: ";
	cin.getline(cad1, TOPE);

	longitud=longitud_cadena(cad1);

	cout << "La longitud de la cadena es: " << longitud << endl;

	vaciar_cadenas(cad1, cad2);

//EJERCICIO 10
	bool palindromo;

	cout << "\nPALINDROMO" << endl;

	cout << "Introduce la cadena: ";
	cin.getline(cad1, TOPE);

	palindromo=palindromo_rec(cad1);


	if(palindromo)
	cout << "\nEs palindromo" << endl;
	else
	cout << "\nNo es palindromo" << endl;

	vaciar_cadenas(cad1, cad2);

//EJERCICIO 11
	int resultado;

	cout << "\nCOMPARA CADENA" << endl;

	cout << "Introduzca la primera cadena: ";
	cin.getline(cad1, TOPE);
	cout << "Introduzca la segunda cadena: ";
	cin.getline(cad2, TOPE);

	resultado=compara_cadenas(cad1, cad2);

	if(resultado==0)
	cout << "Las cadenas tienen el mismo tamano" << endl;
	else if(resultado >0)
	cout << "Cadena 1 mayor que cadena 2" << endl;
	else
	cout << "Cadena 1 menor que cadena 2" << endl;

	vaciar_cadenas(cad1, cad2);

//EJERCICIO 12
	cout << "\nCOPIAR CADENA" << endl;

	cout << "Introduzca la cadena a copiar: ";
	cin.getline(cad2, TOPE);

	cout << "Esta es la cadena : " << cad2 << endl;
	cout << "Copiando en cadena nueva...\n";
	copiar_cadena(cad1,cad2);
	cout << "Cadena nueva: " << cad1 << endl;

	vaciar_cadenas(cad1, cad2);

//EJERCICIO 13
	cout << "\nENCADENAR CADENA" << endl;

	cout << "Introduzca la primera cadena: ";
	cin.getline(cad1, TOPE);
	cout << "Introduzca la segunda cadena a concatenar: ";
	cin.getline(cad2, TOPE);

	encadenar_cadena(cad1,cad2);

	cout << cad1 << endl;

	vaciar_cadenas(cad1, cad2);

//EJERCICIO 14
	int inicio, longitud1;

	cout << "\nSUBCADENA" << endl;

	cout << "Introduzca la cadena: ";
	cin.getline(cad2, TOPE);
	cout << "Indique el incio: ";
	cin >> inicio;
	cout << "Indique la longitud: ";
	cin >> longitud1;

	subcadena(cad1, cad2, inicio, longitud1);

	cout << cad1 << endl;

	vaciar_cadenas(cad1, cad2);

//EJERCICIO 15
	cout << "\nINVERTIR CADENA" << endl;

	cout << "Introduzca la cadena: ";
	cin.getline(cad2, TOPE);

	invertir_cadena(cad1, cad2);

	cout << "La cadena invertida es: " << cad1 << endl;


	cout << "Su nueva subcadena es: \n" << cad1 << endl;

	vaciar_cadenas(cad1, cad2);
}
