#ifndef UTILIDADES_H
#define UTILIDADES_H

//EJERCICIO 1
enum TipoRedimension {DeUnoEnUno,EnBloques,Duplicando};
int * Redimensiona (int * p, TipoRedimension Redimensiona, int & cap);
void Limpiar_Ventana();
void Mostrar(int *vec, const int TAM);

//EJERCICIO 2
const int TAM_NOMBRE = 80, TAM = 100, TAM_DNI = 10;
struct RegAlumno{
  char *DNI;
  char *apellido_nombre;
	double *notas;
};
void NotaMedia(RegAlumno *alumnos, double media[], double pesos[], int n_alumnos, int NUM_NOTAS);
bool Comprobar(double pesos[], int NUM_NOTAS);
void lee_linea(char c[], int tamano);
char * LeerNombre();
void RellenaDatos(RegAlumno *alumnos, int n_alum, int NUM_NOTAS);
void Ponderaciones(double pesos[], int NUM_NOTAS);
void ImprimirDatos(RegAlumno *alumnos, double media[], int n_alumnos, int NUM_NOTAS);
void Ordena_Calif_Alumnos(RegAlumno *alumnos, double media[], int n_alumnos);
void Muestra_Ponderaciones(double pesos[], int NUM_NOTAS);
void Muestra_Calif(double calificacion_media[], int num_alumnos);
void ImprimirDatos_arg(RegAlumno *alumnos, double calificacion_media[], double inicio_nota, double final_nota, int num_alumnos, int NUM_NOTAS);

#endif
