/*14. En una clase de 5 alumnos se han realizado tres examenes y se requiere
determinar el numero de:
	a) Alumnos que aprobaron todos los examenes.
	b) Alumnos que aprobaron al menos un examen.
	c) Alumnos que aprobaron unicamente el ultimo examen.

Realice un programa que permita la lectura de los datos y el calculo de las
estadisticas.
*/

#include<iostream>

using namespace std;

int main(){
	int examen1,examen2,examen3;
	int aprobaron_todos_examenes=0,aprobaron_almenos_uno=0,aprobaron_ultimo=0, suspendieros_todos=0;

	for(int i=1;i<=5;i++){
		cout<<i<<". Digite la nota del primer examen: "; cin>>examen1;
		cout<<i<<". Digite la nota del segundo examen: "; cin>>examen2;
		cout<<i<<". Digite la nota del tercer examen: "; cin>>examen3;
		cout<<"\n";

		//examinando la opcion a
		if((examen1>=5)&&(examen2>=5)&&(examen3>=5)){
			aprobaron_todos_examenes++;
		}

		//examinando la opcion b
		if((examen1>=5)||(examen2>=5)||(examen3>=5)){
			aprobaron_almenos_uno++;
		}

		//examinando la opcion c
		if((examen1<5)&&(examen2<5)&&(examen3>=5)){
			aprobaron_ultimo++;
		}

		if((examen1<5)&&(examen2<5)&&(examen3<5)){
			suspendieros_todos++;
		}
	}

	cout<<"\na) Aprobaron todos los examenes: "<<aprobaron_todos_examenes;
	cout<<"\nb) Aprobaron almenos un examen: "<<aprobaron_almenos_uno;
	cout<<"\nc) Aprobaron unicamente el ultimo examen: "<<aprobaron_ultimo;
	cout<<"\nd) Suspendieros todos los examenes: "<<suspendieros_todos;

	return 0;
}
