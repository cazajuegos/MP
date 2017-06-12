/*EJERCICIO 15
Escriba una función a la que le damos una cadena de caracteres. Queremos obtener una
nueva cadena, resultado de invertir la primera.*/

#include <iostream>

using namespace std;

void invertir_cadena(char *cad1, const char *cad2){
	int lon = 0;
	while(*(cad2+lon++)!='\0');
	lon--;
	for(int i = 0; i < lon; i++){
		*(cad1+i) = *(cad2 + lon - i - 1);
	}
	*(cad1+lon)='\0';
}

int main(){
	const int TOPE = 100;
	char cad1[TOPE], cad2[TOPE];

	cout << "Introduzca la cadena: ";
	cin.getline(cad2, TOPE);

	invertir_cadena(cad1, cad2);

	cout << "La cadena invertida es: " << cad1 << endl;

}
