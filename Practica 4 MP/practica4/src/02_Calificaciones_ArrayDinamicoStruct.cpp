#include <iostream>
#include <cstdlib>
#include <limits>
#include <cstring>
#include "utilidades.h"

using namespace std;

int main(int argc, char const *argv[]) {
  int  NUM_NOTAS, n_alum;
  RegAlumno *alumnos = new RegAlumno[TAM];

  cout << "Introduzca el numero de ponderaciones: ";
  cin >> NUM_NOTAS;
  double *pesos = new double[NUM_NOTAS];

  Limpiar_Ventana();

  Ponderaciones(pesos, NUM_NOTAS);

  Limpiar_Ventana();

  Muestra_Ponderaciones(pesos, NUM_NOTAS);

  cout << "\nIntroduzca el numero de alumnos: ";
  cin >> n_alum;

  double *calificacion_media = new double[n_alum];

  Limpiar_Ventana();  

  RellenaDatos(alumnos, n_alum, NUM_NOTAS);
  NotaMedia(alumnos, calificacion_media, pesos, n_alum, NUM_NOTAS);
  Ordena_Calif_Alumnos(alumnos, calificacion_media, n_alum);
  Muestra_Calif(calificacion_media, n_alum);

  if(argc == 3){
    double inicio_nota = atof ( *(argv + 1) );
    double final_nota = atof ( *(argv + 2) );
    ImprimirDatos_arg(alumnos, calificacion_media, inicio_nota, final_nota, n_alum, NUM_NOTAS);
  }
  else if(argc == 1){
    ImprimirDatos(alumnos, calificacion_media, n_alum, NUM_NOTAS);
  }
  else{
    cout << "Error de argumentos" << endl;
  }

  delete[] pesos;
  delete[] calificacion_media;
  delete[] alumnos;

}
