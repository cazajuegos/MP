/*3. Escribe un programa que lea de la entrada estandar un vector de numeros y
muestre en la salida estandar los numeros del vector con sus indices asociados.*/

#include<iostream>
#include<curses.h>

using namespace std;

int main(){
	int numeros[100],n;

	cout<<"Digite el numero de elementos: ";
	cin>>n;

	for(int i=0;i<n;i++){
		cout<<"Digite un numero: ";
		cin>>numeros[i]; //Guardamos los numeros en el arreglo
	}

	//Ahora, vamos a mostrar los numeros con sus indices asociados

	for(int i=0;i<n;i++){
		cout<<i<<" -> "<<numeros[i]<<endl; //Mostrando los numeros
	}

	getch();
	return 0;
}
