/*Ejercicio 7: Pedir su nombre al usuario y devolver el numero de vocales que hay.
NOTA: Recuerda que debes utilizar punteros . */

#include<iostream>
#include<ncurses.h>
#include<string.h>
using namespace std;

//Prototipo de Funcion
void pedirDatos();
int contarVocales(char *);

char nombreUsuario[30];

int main(){
	pedirDatos();
	cout<<"\nNumero de vocales en el nombre: "<<contarVocales(nombreUsuario);

	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite su nombre: ";
	cin.getline(nombreUsuario,30,'\n');
}

int contarVocales(char *nombre){
	int cont = 0;

	while(*nombre){ //mientras nombre no sea nulo '\0'
		switch(toupper(*nombre)){
			case 'A':
			case 'E':
			case 'I':
			case 'O':
			case 'U': cont++;
		}
		nombre++;
	}

	return cont;
}
