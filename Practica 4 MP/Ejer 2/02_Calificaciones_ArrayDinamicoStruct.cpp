#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>

using namespace std;

const int TAM_NOMBRE = 80;
const int TAM = 100;
const int TAM_DNI = 10;

struct RegAlumno{
  char *DNI;
  char *apellido_nombre;
	double *notas;
};

void NotaMedia(RegAlumno *alumnos, double media[], double pesos[], int n_alumnos, int NUM_NOTAS){
	double suma=0;

	for(int i=0; i<n_alumnos; i++){
		for(int j=0; j<NUM_NOTAS; j++){
			suma = suma+((alumnos[i].notas[j] * pesos[j]) / 100.0);
		}
  	media[i]=suma;
  	suma=0;
	}
}

bool Comprobar(double pesos[], int NUM_NOTAS){
	bool comprobar = false;
	double suma;
	int i=0;
	while(i < NUM_NOTAS){
		suma += pesos[i];
		i++;
	}
	return (suma == 100);
}

void lee_linea(char c[], int tamano){
     do{
         cin.getline(c, tamano);
     } while (c[0] == '\0');
}

char * LeerNombre(){
     char cadena[300];
     char *p;

     lee_linea (cadena, 300);

     p = new char [ strlen (cadena) + 1 ];

     strcpy( p, cadena );

     return p;
}

void RellenaDatos(RegAlumno *alumnos, int n_alum, int NUM_NOTAS){
	for(int i = 0; i < n_alum; i++){
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout <<i+1<< ". Introduzca su nombre y apellidos: ";
    alumnos[i].apellido_nombre = LeerNombre();
    cout <<i+1<< ". DNI: ";
    alumnos[i].DNI = LeerNombre();
    alumnos[i].notas = new double[NUM_NOTAS];
		for(int j=0; j < NUM_NOTAS; j++){
			cout <<j+1<< ". Nota: ";
			cin >> alumnos[i].notas[j];
		}
		system("/usr/bin/clear");
	}
}

void Ponderaciones(double pesos[], int NUM_NOTAS){
	cout << "Digite las ponderaciones: \n";
	for(int i = 0; i < NUM_NOTAS; i++){
		cout << i+1 << ". Ponderacion: ";
		cin >> pesos[i];
	}

	if(Comprobar(pesos, NUM_NOTAS) == false){
		cout << "Las ponderaciones introducidas no son correctas" << endl;
		exit(0);
	}
	else{
		cout << "Ponderaciones introducidas correctas" << endl;
	}
}

void ImprimirDatos(RegAlumno *alumnos, double media[], int n_alumnos, int NUM_NOTAS){
	for(int i=0; i<n_alumnos; i++){
		cout << "\n\n***" << i+1. << ".ALUMNO***\n";
		cout << alumnos[i].apellido_nombre << " con D.N.I -> " << alumnos[i].DNI << endl;
		for(int j=0; j<NUM_NOTAS; j++){
			cout << j+1 << ".Nota: " << alumnos[i].notas[j] << endl;
		}
		cout << "NOTA MEDIA: " << media[i];
	}
	cout << "\n";
}

void Ordena_Calif_Alumnos(RegAlumno *alumnos, double media[], int n_alumnos){
	for(int i = 0; i < n_alumnos-1; i++){
		int menor = i;
		for(int j = i+1; j < n_alumnos; j++){
			if(media[j] < media[menor]){
				menor = j;
			}
		}
		double aux = media[menor];
		media[menor] = media[i];
		media[i] = aux;
		RegAlumno aux2 = alumnos[menor];
		alumnos[menor] = alumnos[i];
		alumnos[i] = aux2;
	}
}

void Muestra_Ponderaciones(double pesos[], int NUM_NOTAS){
	cout << "Estas son las ponderaciones:\n";
	for(int i=0; i<NUM_NOTAS; i++){
		cout << i+1 << ".Ponderacion: " << pesos[i] << "\n";
	}
}

void Muestra_Calif(double calificacion_media[], int num_alumnos){
	cout << "Calificaciones medias ordenadas:\n";
	for(int i = 0; i<num_alumnos; i++){
		cout << calificacion_media[i] << "  ";
	}
	cout << "\n";
}

void ImprimirDatos_arg(RegAlumno *alumnos, double calificacion_media[], double inicio_nota, double final_nota, int num_alumnos, int NUM_NOTAS){
	cout << "\nAlumnos filtrado por las notas: " << inicio_nota << "-" << final_nota << endl;

	for(int i=0; i<num_alumnos; i++){
		if((calificacion_media[i] >= inicio_nota) && (calificacion_media[i] <= final_nota)){
			cout << "Nombre y apellidos: " << alumnos[i].apellido_nombre << "con D.N.I -> " << alumnos[i].DNI << endl;
			for (int j=0; j<NUM_NOTAS; j++){
				cout << j+1 << ".Nota: " << alumnos[i].notas[j] << endl;
			}
			cout << "NOTA MEDIA: " << calificacion_media[i] << endl;
		}
	}
}

int main(int argc, char const *argv[]) {
  int  NUM_NOTAS, n_alum;
  RegAlumno *alumnos;
  alumnos = new RegAlumno[TAM];

  cout << "Introduzca el numero de ponderaciones: ";
  cin >> NUM_NOTAS;
  double *pesos = new double[NUM_NOTAS];

  system("/usr/bin/clear");

  Ponderaciones(pesos, NUM_NOTAS);

  system("/usr/bin/clear");

  Muestra_Ponderaciones(pesos, NUM_NOTAS);

  cout << "\nIntroduzca el numero de alumnos: ";
  cin >> n_alum;

  double *calificacion_media = new double[n_alum];

  system("/usr/bin/clear");

  RellenaDatos(alumnos, n_alum, NUM_NOTAS);
  NotaMedia(alumnos, calificacion_media, pesos, n_alum, NUM_NOTAS);
  Ordena_Calif_Alumnos(alumnos, calificacion_media, n_alum);
  Muestra_Calif(calificacion_media, n_alum);

  if(argc == 3){
    double inicio_nota = atoi ( *(argv + 1) );
    double final_nota = atoi ( *(argv + 2) );
    ImprimirDatos_arg(alumnos, calificacion_media, inicio_nota, final_nota, n_alum, NUM_NOTAS);
  }
  else if(argc == 1){
    ImprimirDatos(alumnos, calificacion_media, n_alum, NUM_NOTAS);
  }
  else{
    cout << "Error de argumentos" << endl;
  }

  delete[] alumnos;
  delete[] pesos;
  delete[] calificacion_media;
}
