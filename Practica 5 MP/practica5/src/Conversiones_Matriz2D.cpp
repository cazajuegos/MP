#include <iostream>
#include "Conversiones_Matriz2D.h"

using namespace std;

int **Crea_Matriz2D_1(const int F, const int C){
    int **matriz = new int *[F];

    for(int i = 0; i < F; i++){
      matriz[i] = new int[C];
    }

    return matriz;
}

void Borra_Matriz2D_1(int **matriz, const int F){
    for(int i = 0; i < F; i++){
      delete [] matriz[i];
    }
    delete [] matriz;
}

int **Crea_Matriz2D_2(const int F, const int C){
    int **matriz = new int *[F];
    matriz[0] = new int[F*C];

    for(int i = 1; i < F; i++){
      matriz[i] = matriz[i - 1] + C;
    }

    return matriz;
}

void Borra_Matriz2D_2(int **matriz, const int F){
  delete [] matriz[0];
  delete [] matriz;
}

int **Matriz2D_1_a_Matriz2D_2(int **matriz2d_1, int F, int C){
  int **matriz2d_2 = Crea_Matriz2D_2(F, C);

  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      matriz2d_2[i][j] = matriz2d_1[i][j];
    }
  }

  return matriz2d_2;
}

int **Matriz2D_2_a_Matriz2D_1(int **matriz2d_2, int F1, int C1){
  int **matriz2d_1 = Crea_Matriz2D_1(F1, C1);

  for(int i = 0; i < F1; i++){
    for(int j = 0; j < C1; j++){
      matriz2d_1[i][j] = matriz2d_2[i][j];
    }
  }

  return matriz2d_1;
}

void Muestra_Matriz(int **matriz, const int F, const int C){
  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      cout << "[" << matriz[i][j] << "]" << " ";
    }
    cout << endl;
  }
}

void Rellena_Aleatoriamente(int **matriz, const int F, const int C){
  time_t t;
	srand ((int) time(&t));

  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      matriz[i][j] = (rand() % NUM_VALORES) + MIN;
    }
  }
}
