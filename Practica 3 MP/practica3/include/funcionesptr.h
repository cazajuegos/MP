#ifndef FUNCIONESPTR_H
#define FUNCIONESPTR_H

const int MIN = 1, MAX=25, NUM_VALORES = MAX-MIN+1;
int PosMayor(const int *pv, int izda, int dcha);
void Rellena(int *cad, int total);
void Rellena_Asigna(int *cad, int **vec, int total);
void Mostrar(const int *cadena, int total);
void MostrarPtr(int **ptr, int inicio, int final);
void Ordena(int *vec, int **ptr, int izda, int dcha);

#endif
