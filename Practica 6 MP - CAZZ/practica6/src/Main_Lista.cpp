#include <iostream>
#include <cstdlib>
#include "Lista.h"
using namespace std;


int main (void){
	Lista l1=0, l2=0;

	system("/usr/bin/clear");
	cout << "--------" << endl << "LISTA\n" << "--------" << endl;

	// Lee y ordena la lista 1
	l1 = LeeLista();
	PintaLista(l1);
	cout << "Secuencia 1 ordenada tiene " << CuentaElementos(l1) << " elementos\n";
	OrdenaSeleccionLista(l1);
	PintaLista(l1);

	cout << "----------------------------------------------------" << endl;
	// Lee y ordena la lista 2
	l2 = LeeLista();
	PintaLista(l2);
	cout << "Secuencia 2 ordenada tiene " << CuentaElementos(l2) << " elementos\n";
	OrdenaSeleccionLista(l2);
	PintaLista(l2);

	cout << "----------------------------------------------------" << endl;

	// Mezcla las dos listas
	Lista l3 = MezclaListas(l1, l2);
	cout << "Mezcla de ambas secuencias tiene: " << CuentaElementos(l3) << " elementos\n";
	PintaLista(l3);

	//Elimina elemento;
	int num;
	cout << "Elemento a eliminar?: ";
	cin >> num;
	EliminaValor(l3, num);
	PintaLista(l3);

	LiberaLista(l1);
	LiberaLista(l2);
	LiberaLista(l3);
	return 0;
}
