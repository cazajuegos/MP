#ifndef FUNCIONESCALIF_H
#define FUNCIONESCALIF_H

const int NUM_NOTAS = 4;
const int TAM_NOMBRE = 80;
const int TAM = 100;
struct RegAlumno;
extern RegAlumno alumnos[TAM];
void NotaMedia(double media[], double pesos[], int n_alumnos);
bool Comprobar(double pesos[]);
void RellenaDatos(int n_alum);
void Ponderaciones(double pesos[]);
void ImprimirDatos(double media[], int n_alumnos);
void Ordena_Calif_Alumnos(double media[], int n_alumnos);
void Muestra_Ponderaciones(double pesos[]);
void Muestra_Calif(double calificacion_media[], int num_alumnos);
void ImprimirDatos_arg(double calificacion_media[], double inicio_nota, double final_nota, int num_alumnos);

#endif
