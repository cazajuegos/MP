/*Ejercicio 5: Escriba una plantilla de funciun llamada despliegue() que despliegue el valor
del argumento unico que se le transmite cuando es invocada la funcion.*/

#include<iostream>
#include<curses.h>
using namespace std;

template <class TIPOD>
void despliegue(TIPOD dato);

int main(){
	int dato1 = 4;
	float dato2 = 5.678;
	double dato3 = 15.6789;
	char dato4 = 'a';

	despliegue(dato1);
	despliegue(dato2);
	despliegue(dato3);
	despliegue(dato4);


	getch();
	return 0;
}

template <class TIPOD>
void despliegue(TIPOD dato){

	cout<<"El dato es: "<<dato<<endl;
}
