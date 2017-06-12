/*EJERCICIO 12
Escriba la funci�n copiar_cadena, que
copiar� una cadena de caracteres en otra. El resultado de la copia ser� el primer argumento
de la funci�n. La cadena original (segundo argumento) no se modifica.*/

#include <iostream>
using namespace std;

char copiar_cadena(char *cad1, const char *cad2){
	char *p1 = cad1;
	for(const char *p2 = cad2; *p2 != '\0'; p2++){
		*p1 = *p2;
		p1++;
	}
	return *(cad1);
}


int main(){
	int TOPE = 100;
	char cad1[TOPE], cad2[TOPE];


	cout << "Introduzca la cadena a copiar: ";
	cin.getline(cad2, TOPE);

	cout << "Esta es la cadena : " << cad2 << endl;
	cout << "Copiando en cadena nueva...\n";
	copiar_cadena(cad1,cad2);
	cout << "Cadena nueva: " << cad1 << endl;



}
