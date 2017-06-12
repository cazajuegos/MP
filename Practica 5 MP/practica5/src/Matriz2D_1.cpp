#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Matriz2D_1.h"

using namespace std;

void Limpia_Consola(){
  system("/usr/bin/clear");
}

//APARTADO A
int **Crea_Matriz2D_1(const int F, const int C){
    int **matriz = new int *[F];

    for(int i = 0; i < F; i++){
      matriz[i] = new int[C];
    }

    return matriz;
}

//APARTADO B
void Borra_Matriz2D_1(int **matriz, const int F){
    for(int i = 0; i < F; i++){
      delete [] matriz[i];
    }
    delete [] matriz;
}

//APARTADO C
int **Crea_Rellena(const int F, const int C){
  int **matriz = Crea_Matriz2D_1(F, C);

  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      cout << "POSICION " << i+1 << "." << j+1 << ": ";
      cin >> matriz[i][j];
    }
  }

  return matriz;
}

//APARTADO D
int **Crea_Rellena_Aleatoriamente(const int F, const int C){
  int **matriz = Crea_Matriz2D_1(F, C);

  time_t t;
	srand ((int) time(&t));

  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      matriz[i][j] = (rand() % NUM_VALORES) + MIN;
    }
  }

  return matriz;
}

//APARTADO E
void Muestra_Matriz(int **matriz, const int F, const int C){
  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      cout << "[" << matriz[i][j] << "]" << " ";
    }
    cout << endl;
  }
}

//APARTADO F
int **Copia_Matriz(int **matriz, const int F, const int C){
  int **copia_matriz = Crea_Matriz2D_1(F, C);

  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      copia_matriz[i][j] = matriz[i][j];
    }
  }

  return copia_matriz;
}

//APARTADO G
int **Submatriz(int **matriz, int inicio_F, int inicio_C, int fin_F, int fin_C){
    int **submatriz = Crea_Matriz2D_1(fin_F-inicio_F+1, fin_C-inicio_C+1);
    int fnew = 0, cnew = 0;

    for(int i = inicio_F; i < fin_F+1; i++){
      for(int j = inicio_C; j < fin_C+1; j++){
        submatriz[fnew][cnew] = matriz[i][j];
        cnew++;
      }
      fnew++;
      cnew=0;
    }

    return submatriz;
}

//APARTADO H
int **Elimina_Fila(int **matriz, int &F, int C, int fila_borrar){
  int **matriz_mod = Crea_Matriz2D_1(F-1, C);
  int borrar = 0;

  for(int i = 0; i < F; i++){
    if(i != fila_borrar){
      for(int j = 0; j < C; j++){
        matriz_mod[borrar][j] = matriz[i][j];
      }
      borrar++;
    }
  }

  return matriz_mod;
}

//APARTADO I
int **Elimina_Columna(int ** matriz, int F, int &C, int col_borrar){
  int **matriz_mod = Crea_Matriz2D_1(F, C-1);
  int borrar = 0;

  for(int j = 0; j < C; j++){
    if(j != col_borrar){
      for(int i = 0; i < F; i++){
        matriz_mod[i][borrar] = matriz[i][j];
      }
      borrar++;
    }
  }

  return matriz_mod;
}

//APARTADO J
int **Traspuesta(int **matriz, int F, int C){
  int **traspuesta = Crea_Matriz2D_1(C, F);

  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      traspuesta[j][i] = matriz[i][j];
    }
  }

  return traspuesta;
}

//APARTADO K
int **Filas_Inv(int **matriz, int F, int C){
  int **f_inv = Crea_Matriz2D_1(F, C);
  int nuevo = 0;

  for(int i = F-1; i >= 0; i--){
    for(int j = 0; j < C; j++){
      f_inv[nuevo][j] = matriz[i][j];
    }
    nuevo++;
  }

  return f_inv;
}
