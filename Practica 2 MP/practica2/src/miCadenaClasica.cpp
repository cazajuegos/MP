#include <iostream>
#include <cstring>
#include "miCadenaClasica.h"

using namespace std;

//EJERCICIO 9
int longitud_cadena(const char *cadena){
	const char *p;
	for(p=cadena; *p != '\0'; p++);
	return(p-cadena);
}

//EJERCICIO 10
bool palindromo_rec (const char *cad){
	bool palindromo = true;
	int lng = 0, ini = 0;
	//Calcula longitud cadena.
	while(*(cad + lng++)!='\0'); lng--;
	//palindromo
	while(palindromo && ini < lng){
		char lft = *(cad + ini), rgt = *(cad + lng - 1);
		cout << lft << " - " << rgt;
		if(lft == ' ' || rgt == ' '){
			if(lft == ' ') lng++;
			if(rgt == ' ') ini--;
		}else if(lft == rgt){
			lng--; ini++;
		}else{
			palindromo = false;
		}
	}
	return palindromo;
}

//EJERCICIO 11
int compara_cadenas(const char *cad1, const char *cad2){
	char l1, l2;

	l1=longitud_cadena(cad1);
	l2=longitud_cadena(cad2);

	return (l1-l2);
}

//EJERCICIO 12
char copiar_cadena(char *cad1, const char *cad2){
	char *p1 = cad1;
	for(const char *p2 = cad2; *p2 != '\0'; p2++){
		*p1 = *p2;
		p1++;
	}
	return *(cad1);
}

//EJERCICIO 13
char encadenar_cadena(char *cad1, const char *cad2){
	char *p1;
	const char *p2=cad2;

	for(p1 = cad1; *p1 != '\0'; p1++);

	while(*p2 != '\0'){
	*p1=*p2;
	p1++;
	p2++;
	}

	return *(cad1 = p1);

}

//EJERCICIO 14
char subcadena(char *cad1, const char *cad2, int inicio, int longitud){

	for(const char *p2=cad2+inicio; longitud != 0; longitud--){
		*cad1=*p2;
		cad1++;
		p2++;
	}

	return *cad1;
}

//EJERCICIO 15
void invertir_cadena(char *cad1, const char *cad2){
	int lon = 0;
	while(*(cad2+lon++)!='\0');
	lon--;
	for(int i = 0; i < lon; i++){
		*(cad1+i) = *(cad2 + lon - i - 1);
	}
	*(cad1+lon)='\0';
}

void vaciar_cadenas(char *cad1, char *cad2){
	strcpy(cad1,"\0");
	strcpy(cad2,"\0");
}
