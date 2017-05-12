/*EJERCICIO 10
Escriba una función a la que le damos una cadena de caracteres y calcule si ésta es un
palíndromo.*/

#include <iostream>
#include <string.h>

using namespace std;

bool palindromo_rec (const char *cad){
	bool palindromo = true;
	int lng = 0, ini = 0;
	//Calcula longitud cadena.
	while(*(cad + lng++)!='\0'); lng--;
	//palindromo
	while(palindromo && ini < lng){
		char lft = *(cad + ini), rgt = *(cad + lng - 1);
		cout << lft << " - " << rgt;
		if(lft == ' ' || rgt == ' '){
			if(lft == ' ') lng++;
			if(rgt == ' ') ini--;
		}else if(lft == rgt){
			lng--; ini++;
		}else{
			palindromo = false;
		}
	}
	return palindromo;
}


int main(){
	const int TOPE = 100;
	char cad1[TOPE];
	bool palindromo;

	cout << "Introduce la cadena: ";
	cin.getline(cad1, TOPE);

	palindromo=palindromo_rec(cad1);


	if(palindromo)
	cout << "\nEs palindromo" << endl;
	else
	cout << "\nNo es palindromo" << endl;

}
