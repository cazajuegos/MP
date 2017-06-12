/*1. Hacer una estructura llamada corredor, en la cual se tendran los siguientes
campos: Nombre, edad, sexo, club, pedir datos al usuario para un corredor, y asignarle
una categoria de competicion:
- Juvenil <= 18 años
- Señor <= 40 años
- Veterano > 40 años
Posteriormente imprimir todos los datos del corredor, incluida su categoria de
competicion.*/

#include<iostream>
#include<curses.h>
#include<string.h>
using namespace std;

struct Corredor{
	char nombre[20];
	int edad;
	char sexo[10];
	char club[20];
}c1;

int main(){
	char categoria[20];

	cout<<"Nombre: "; cin.getline(c1.nombre,20,'\n');
	cout<<"Edad: "; cin>>c1.edad;
	fflush(stdin);  //AMBOS SIRVEN PARA LIMPIAR EL BUFFER
	cin.ignore(100, '\n');
	cout<<"Sexo: "; cin.getline(c1.sexo,10,'\n');
	cout<<"Club: "; cin.getline(c1.club,20,'\n');

	if(c1.edad <= 18){
		strcpy(categoria,"Juvenil");
	}
	else if(c1.edad <= 40){
		strcpy(categoria,"Senior");
	}
	else{
		strcpy(categoria,"Veterano");
	}

	cout<<"\n\nMostrando Datos"<<endl;
	cout<<"Nombre: "<<c1.nombre<<endl;
	cout<<"Edad: "<<c1.edad<<endl;
	cout<<"Sexo: "<<c1.sexo<<endl;
	cout<<"Club: "<<c1.club<<endl;
	cout<<"Categoria: "<<categoria<<endl;

	getch();
	return 0;
}
