/*EJERCICIO 13
Escriba la funci�n encadenar_cadena,
que a�adir� una cadena de caracteres al final de otra. El resultado se dejar� en el primer
argumento de la funci�n. La cadena que se a�ade (segundo argumento) no se modifica.*/

#include <iostream>

using namespace std;

char encadenar_cadena(char *cad1, const char *cad2){
	char *p1;
	const char *p2=cad2;

	for(p1 = cad1; *p1 != '\0'; p1++);

	while(*p2 != '\0'){
	*p1=*p2;
	p1++;
	p2++;
	}
	return *(cad1);
}


int main(){
	int TOPE = 100;
	char cad1[TOPE], cad2[TOPE];

	cout << "Introduzca la primera cadena: ";
	cin.getline(cad1, TOPE);
	cout << "Introduzca la segunda cadena a concatenar: ";
	cin.getline(cad2, TOPE);

	encadenar_cadena(cad1,cad2);

	cout << cad1 << endl;


}
