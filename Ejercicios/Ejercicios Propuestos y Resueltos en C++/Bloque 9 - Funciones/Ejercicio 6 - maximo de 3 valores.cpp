/*Ejercicio 6: Escriba una plantilla de funcion llamada maximo() que devuelva el valor
maximo de tres argumentos que se transmitan a la funciun cuando sea llamada.
Suponga que los tres argumentos seran del mismo tipo de datos.*/

#include<iostream>
#include<curses.h>
using namespace std;

template <class T>
T maximo(T dato1, T dato2, T dato3);

int main(){
	char dato1='e',dato2='f',dato3='a';
	int num1=2, num2=5, num3=9;

	cout<<"El maximo valor es: "<<maximo(dato1,dato2,dato3) << endl;
	cout << "El maximo valor es: " << maximo(num1, num2, num3) << endl;

	getch();
	return 0;
}

template <class T>
T maximo(T dato1, T dato2, T dato3){
	T max;

	if((dato1 > dato2) && (dato1 > dato3)){
		max = dato1;
	}
	else{
		 if((dato2>dato1) && (dato2>dato3)){
			max = dato2;
		}
		else{
			max = dato3;
		}
	}
	return max;
}
