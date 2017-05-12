/*EJERCICIO 10
Escriba una función a la que le damos una cadena de caracteres y calcule si ésta es un
palíndromo.*/

#include <iostream>
#include <string.h>

using namespace std;

bool palindromo_rec (const char *cadena, int izda, int dcha){
	if (izda >= dcha) return (true);
	if (*(cadena+izda)==' ') return palindromo_rec (cadena, izda+1, dcha);
	if (*(cadena+dcha)==' ') return palindromo_rec (cadena, izda, dcha-1);
	if (toupper(*(cadena+izda)) == toupper(*(cadena+dcha))) return palindromo_rec (cadena, izda+1, dcha-1);
	else
	return(false);
}


int main(){
	const int TOPE = 100;
	char cad1[TOPE];
	int izda, dcha;
	bool palindromo;

	cout << "Introduce la cadena: ";
	cin.getline(cad1, TOPE);

	cout << "Su izquierda y derecha: ";
	cin >> izda; cin >> dcha;

	palindromo=palindromo_rec(cad1, izda, dcha);

	if(palindromo)
	cout << "Es palindromo" << endl;
	else
	cout << "No es palindromo" << endl;

}

