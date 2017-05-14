#ifndef CONVERSIONES_MATRIZ2D_H
#define CONVERSIONES_MATRIZ2D_H

const int MIN = 1, MAX=9, NUM_VALORES = MAX-MIN+1;

int **Crea_Matriz2D_1(const int F, const int C);
void Borra_Matriz2D_1(int **matriz, const int F);
int **Crea_Matriz2D_2(const int F, const int C);
void Borra_Matriz2D_2(int **matriz, const int F);
int **Matriz2D_1_a_Matriz2D_2(int **matriz2d_1, int F, int C);
int **Matriz2D_2_a_Matriz2D_1(int **matriz2d_2, int F1, int C1);
void Muestra_Matriz(int **matriz, const int F, const int C);
void Rellena_Aleatoriamente(int **matriz, const int F, const int C);

#endif
