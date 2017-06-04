#include <iostream>
#include "Lista.h"
using namespace std;

Lista LeeLista (void){
	PNodo inic=0;
	PNodo fin, nuevo;
	TipoBase valor;

	cout << "Introduzca un valor (-1 FIN): ";
	cin >> valor;

	if (valor >= 0)	{
		inic = new Nodo;
		inic->valor = valor;
		inic->sig = 0;

		fin = inic;

		cout << "Introduzca un valor (-1 FIN): ";
		cin >> valor;

		while (valor >= 0) {
			nuevo = new Nodo;
			nuevo->valor = valor;

			fin->sig = nuevo;
			fin = nuevo;

			cout << "Introduzca un valor (-1 FIN): ";
			cin >> valor;
		}

		fin->sig = 0;
	}

	return (inic);
}

void PintaLista (const Lista l){
	PNodo p;
	cout << endl;
	int i = 0;
	cout << "LISTA: " << endl;
	for (p=l; p!=0; p=p->sig){
		cout << "Valor(" << i << "): " << p->valor << endl;
		i++;
	}
	cout << endl;

}


void LiberaLista (Lista l){
	PNodo p, ant;

	if (l!=0) {

   		ant = l;
		p = l->sig;

		while (p!=0) {
			delete ant;
			ant = p;
			p = p->sig;
		}

		delete ant;
	}
}


int CuentaElementos (const Lista l){
	PNodo p = l;
	int contador = 0;

	for (PNodo p=l; p!=0; contador++, p=p->sig);

	return (contador);
}



bool   EstaOrdenada (const Lista l){
	PNodo p = l;
	TipoBase anterior;

	bool ordenada = true;

	if (p) {
		anterior = p->valor;
		p = p->sig;
	}
	while (p && ordenada) {
		if (p->valor >= anterior) {
			anterior = p->valor;
			p = p->sig;
		}
		else ordenada = false;
	}

	return (ordenada);
}

void OrdenaSeleccionLista (Lista &l){
	if (l!=0) {

		PNodo primero = l;

		while (primero->sig != 0) {

			TipoBase val_min = primero->valor;
			PNodo pos_min = primero;

			PNodo p = primero->sig;

			while (p!=0) {

				if (p->valor < val_min) {
					val_min = p->valor;
					pos_min = p;
				}
				p = p->sig;
			}

			TipoBase tmp = primero->valor;
			primero->valor = pos_min->valor;
			pos_min->valor = tmp;

			primero = primero->sig;

		}
	}
}

void InsertaOrdenadamente (Lista &l, TipoBase v)
{
	if (l!=0) {

		PNodo p = l;
		PNodo ant = l;

		while ((p->valor < v) && (p->sig!=0)) {
			ant = p;
			p = p->sig;
		}

		PNodo nuevo = new Nodo;
		nuevo->valor = v;

		if (ant==l) {
			nuevo->sig = l;
			l = nuevo;
		}
		else
			if (p->sig==0){
				p->sig = nuevo;
				nuevo->sig = 0;
			}
			else {
				ant->sig = nuevo;
				nuevo->sig = p;
			}
	}
	else {
		l = new Nodo;
		l->valor = v;
		l->sig = 0;
	}

}

void EliminaValor (Lista &l, TipoBase v){
	if (l!=0) {

		PNodo p = l;
		PNodo ant = p;

		while ((p->valor != v) && (p->sig!=0)) {
			ant = p;
			p = p->sig;
		}

		if (p->valor == v) {

			if (p==l)
				l = l->sig;
			else
				ant->sig = p->sig;
			delete p;

		}
	}

}

Lista MezclaListas (Lista &l1, Lista &l2){
	Lista l3=0;
	PNodo p3;

	if ((l1!=0) && (l2!=0)) {

		if (l1->valor < l2->valor) {
			l3 = l1;
			l1 = l1->sig;
		}
		else {
			l3 = l2;
			l2 = l2->sig;
		}

		p3 = l3;

		while ((l1!=0) && (l2!=0)) {

 			if (l1->valor < l2->valor) {
				p3->sig = l1;
				l1 = l1->sig;
			}
			else {
				p3->sig = l2;
				l2 = l2->sig;
			}

			p3 = p3->sig;

		}

		if (l1==0) {
			p3->sig = l2;
			l2 = 0;
		} else {
			p3->sig = l1;
			l1 = 0;
		}

	}

	return (l3);
}
