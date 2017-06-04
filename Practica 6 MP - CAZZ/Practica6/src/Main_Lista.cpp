#include <iostream>
#include <cstdlib>
#include "Lista.h"
using namespace std;


int main (void){
	Lista l1=0, l2=0; // iniciar los punteros a

	system("/usr/bin/clear");
	cout << "--------" << endl << "LISTA\n" << "--------" << endl;

	// Leer y ordenar la lista 1
	l1 = LeeLista ();
	PintaLista (l1);
	cout << "La secuencia ordenada 1 tiene " << CuentaElementos(l1) << " elementos\n";
	OrdenaSeleccionLista (l1);
	PintaLista (l1);

	cout << "----------------------------------------------------" << endl;
	// Leer y ordenar la lista 2
	l2 = LeeLista ();
	PintaLista (l2);
	cout << "La secuencia 2 tiene " << CuentaElementos(l2) << " elementos\n";
	OrdenaSeleccionLista (l2);
	PintaLista (l2);

	cout << "----------------------------------------------------" << endl;

	// Mezclar las dos listas
	Lista l3 = MezclaListas (l1, l2);
	cout << "La mezcla tiene " << CuentaElementos(l3) << " elementos\n";
	PintaLista (l3);


	LiberaLista (l1);
	LiberaLista (l2);
	LiberaLista (l3);
	return 0;
}
