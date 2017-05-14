#ifndef MATRIZ2D_2_H
#define MATRIZ2D_2_H

const int MIN = 1, MAX=9, NUM_VALORES = MAX-MIN+1;

void Limpia_Consola();
//APARTADO A
int **Crea_Matriz2D_2(const int F, const int C);
//APARTADO B
void Borra_Matriz2D_2(int **matriz, const int F);
//APARTADO C
int **Crea_Rellena(const int F, const int C);
//APARTADO D
int **Crea_Rellena_Aleatoriamente(const int F, const int C);
//APARTADO E
void Muestra_Matriz(int **matriz, const int F, const int C);
//APARTADO F
int **Copia_Matriz(int **matriz, const int F, const int C);
//APARTADO G
int **Submatriz(int **matriz, int inicio_F, int inicio_C, int fin_F, int fin_C);
//APARTADO H
int **Elimina_Fila(int **matriz, int &F, int C, int fila_borrar);
//APARTADO I
int **Elimina_Columna(int ** matriz, int F, int &C, int col_borrar);
//APARTADO J
int **Traspuesta(int **matriz, int F, int C);
//APARTADO K
int **Filas_Inv(int **matriz, int F, int C);

#endif
