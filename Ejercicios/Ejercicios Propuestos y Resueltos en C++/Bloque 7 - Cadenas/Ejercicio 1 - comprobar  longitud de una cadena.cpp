/*1. Hacer un programa que pida al usuario que digite una cadena de caracteres, luego
verificar la longitud de la cadena, y si esta supera a 10 caracteres mostrarla en
pantalla, caso contrario no mostrarla.*/

#include<iostream>
#include<curses.h>
#include<string.h>

using namespace std;

int main(){
	char frase[50];

	cout<<"Digite una cadena de caracteres: ";
	cin.getline(frase,50,'\n'); //Guardando la cadena de caracteres

	if(strlen(frase)>10){
		cout<<frase;
	}
	else{
		cout<<"La cadena no supera los 10 caracteres";
	}

	cout << "\nEl tamanio de la cadena es: " << strlen(frase) << endl;

	getch();
	return 0;
}
