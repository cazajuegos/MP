/*Ejercicio 2: Escriba una funcion llamada al_cuadrado() que calcule el cuadrado del
valor que se le transmite y despliegue el resultado. La funcion debera ser capaz de
elevar al cuadrado numeros flotantes*/

#include<iostream>
#include<curses.h>
using namespace std;

void pedirDatos();
void al_cuadrado(float n);

float numero;

int main(){
	pedirDatos();
	al_cuadrado(numero);

	getch();
	return 0;
}

void pedirDatos(){
	cout<<"Digite un numero: ";
	cin>>numero;
}

void al_cuadrado(float n){
	float cuadrado=0;

	cuadrado = numero*numero;

	cout<<"El cuadrado del numero es: "<<cuadrado<<endl;
}
