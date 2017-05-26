#include<iostream>
using namespace std;
const int NUM_NOTAS = 4, TAM_NOMBRE = 80;
struct RegAlumno{
	double *notas;
	char   *dni;
	char   *apellido_nombre;
};

int pow(int n, int i){
    return (i < 1) ? 1 : n * pow(n, i - 1);
}

int charToInt(char *elm){
	int size = 0, number = 0;
	while(*(elm + size) != '\0')size++;
	for(int i = 0; i < size; i++){
		int a = *(elm + i);
		if(a >= '0' && a <= '9'){
			number += (a - '0') * pow(10, size-1-i);
		}
	}
	return number;
}

double *RedimensionaDouble(double *p, int& capacidad){
  double *redimensionado = new double[capacidad + 1];
  for(int i = 0; i < capacidad; i++){
    *(redimensionado + i) = *(p + i);
  }
  delete[] p;

  return redimensionado;
}

RegAlumno *RedimensionaAlumnos(RegAlumno *p, int& capacidad){
  RegAlumno *redimensionado = new RegAlumno[capacidad + 1];
  for(int i = 0; i < capacidad; i++){
    *(redimensionado + i) = *(p + i);
  }
  delete[] p;

  return redimensionado;
}

double *LeePesos (double *ponderaciones, int &num_pesos){
	int pesosUsados = 0;
	double total = 0;
	while(total < 100){
		if(pesosUsados >= num_pesos){
			ponderaciones = RedimensionaDouble(ponderaciones, pesosUsados);
			num_pesos++;
		}
		cout << "Introduzca el peso de la "<< pesosUsados + 1 <<" nota: ";
		double peso;
		cin >> peso;
		*(ponderaciones + pesosUsados) = peso;
		total += peso;
		pesosUsados++;
	}
	if(total > 100){
		cerr << "El total de elementos suman mas de 100.";
	}
	return ponderaciones;
}

void MuestraPesos (double ponderaciones[], int num_pesos){
	cout << "Las ponderaciones son las siguientes." << endl;
	for(int i = 0; i < num_pesos; i++){
		cout << "El "<< i+1 << " examen pondera " << *(ponderaciones + i) << "% de la nota." << endl;
	}
}

void  MuestraVectorAlumnos(RegAlumno *pnt, double *media, int util, double min, double max){
	for(int i = 0; i < util; i++){
		if(media[i] >= min && media[i] <= max){
			RegAlumno alm = *(pnt+i);
			cout << "El alumno: " << alm.apellido_nombre << ", con las siguientes notas: " << endl;
			for(int k = 0; k < 4; k++){
				cout << "Nota " << i << ": " << alm.notas[k] << endl;
			}
			cout << "Obtuvo una media de: " << media[i] << endl;
		}
	}
}

RegAlumno * LeerAlumnos (RegAlumno datos[], int &num_casillas, int totalPesos){
	int used = 0;
	char * fullname = new char[TAM_NOMBRE];
	cout << "Introduzca el nombre y el apellido del alumno: ";
	cin.ignore();
	cin.getline(fullname, TAM_NOMBRE);
	while(fullname[0] != '*'){
		if(used >= num_casillas){
	      		datos = RedimensionaAlumnos(datos, num_casillas);
	      		num_casillas++;
	    	}
	  	char *dni = new char[8];
	  	cout << "Introduzca el DNI: ";
		cin.ignore();
	  	cin.getline(dni, 8);
		double *marks = new double[totalPesos];
		RegAlumno newAlumno;
		for(int i = 0; i < totalPesos; i++){
			cout << "Introduzca la " << i << " nota: ";
			cin >> *(marks + i);
		}
		newAlumno.notas           = marks;
		newAlumno.dni             = dni;
		newAlumno.apellido_nombre = fullname;

		datos[used] = newAlumno;
	    	used++;

		cout << "Introduzca el nombre y el apellido del alumno: ";
	   	fullname = new char[TAM_NOMBRE];
		cin.ignore();
		cin.getline(fullname, TAM_NOMBRE);
	}
	return datos;
}

void CalculaCalificacionesMedias (double medias[], RegAlumno datos[], int num_alumnos, double ponderaciones[], int num_notas){
	for(int i = 0; i < num_alumnos; i++){
		double media = 0;
		for(int k = 0; k < num_notas; k++)
			media += datos[i].notas[k] * ponderaciones[k] / 100.0;
		*(medias + i) = media;
	}
}

void OrdenaVectorAlumnos (RegAlumno datos[], double medias[], int num_alumnos){
	for(int i = 0; i < num_alumnos - 1; i++){
		RegAlumno aux = *(datos + i);
		double nux = *(medias + i);
		int max = i;
		for(int k = i + 1; k < num_alumnos; k++){
			if(*(medias + k) > *(medias + max)){
				max = k;
			}
		}
		*(datos + i) = *(datos + max);
		*(datos + max) = aux;
		*(medias + i) = *(medias + max);
		*(medias + max) = nux;
	}
}

int main(int total, char **args){
	int totalPesos = 1;
	double *pesonotas = new double[totalPesos];
	pesonotas = LeePesos(pesonotas, totalPesos);

	MuestraPesos(pesonotas, totalPesos);
	
	int totalAlumnos = 1;
	RegAlumno *alumnos = new RegAlumno[totalAlumnos];
	alumnos = LeerAlumnos(alumnos, totalAlumnos, totalPesos);
	double calificaciones_medias[totalAlumnos];
	CalculaCalificacionesMedias (calificaciones_medias, alumnos, totalAlumnos, pesonotas, totalPesos);
	OrdenaVectorAlumnos(alumnos, calificaciones_medias, totalAlumnos);
	double left = 0, right = 10.0;
	if(total == 3){
		left 	= charToInt(*(args + 2));
		right 	= charToInt(*(args + 3));
	}
	MuestraVectorAlumnos(alumnos, calificaciones_medias, totalAlumnos, left, right);
	delete[] pesonotas;
	delete[] alumnos;
}
