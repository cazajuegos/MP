#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MIN = 1, MAX=9, NUM_VALORES = MAX-MIN+1;

void Limpia(){
  system("/usr/bin/clear");
}

//APARTADO A
int **Crea_Matriz(const int F, const int C){
    int **matriz = new int *[F];

    for(int i = 0; i < F; i++){
      matriz[i] = new int[C];
    }

    return matriz;
}

//APARTADO B
int **Borra_Matriz(int **matriz, const int F, const int C){
    for(int i = 0; i < F; i++){
      delete [] matriz[i];
    }
    // delete [] matriz;

    return matriz;
}

//APARTADO C
int **Crea_Rellena(const int F, const int C){
  int **matriz = Crea_Matriz(F, C);

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
  int **matriz = Crea_Matriz(F, C);

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
  int **copia_matriz = Crea_Matriz(F, C);

  for(int i = 0; i < F; i++){
    for(int j = 0; j < C; j++){
      copia_matriz[i][j] = matriz[i][j];
    }
  }

  return copia_matriz;
}

//APARTADO G
int **Submatriz(int **matriz, int inicio_F, int inicio_C, int fin_F, int fin_C){
    int **submatriz = Crea_Matriz(fin_F-inicio_F+1, fin_C-inicio_C+1);
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
  int **matriz_mod = Crea_Matriz(F -1, C);

  int borrar = 0;
  for(int i = 0; i < F; i++){
    if(i != fila_borrar){
      borrar++;
      for(int j = 0; j < C; j++){
        matriz_mod[borrar][j] = matriz[borrar][j];
      }
    }
    else{
        i++;
    }
  }

  return matriz_mod;
}

//APARTADO I
int **Elimina_Columna(int ** matriz, int F, int &C, int col_borrar){
  int **matriz_mod = Crea_Matriz(F, C-1);

  for(int j = 0; j < C; j++){
    if(j != col_borrar){
      for(int i = 0; i < F; i++){
        matriz_mod[j][i] = matriz[j][i];
      }
    }
    else{
        j++;
    }
}

  return matriz_mod;
}

//APARTADO J
int **Traspuesta(int **matriz, int F, int C){
  int **traspuesta = Crea_Matriz(C, F);

    for(int i = 0; i < F; i++){
      for(int j = 0; j < C; j++){
        traspuesta[j][i] = matriz[i][j];
      }
    }
    return traspuesta;
  }


int main(int argc, char const *argv[]) {
  int F, C;
  int ** matriz;
  int ** copia_matriz;
  int ** submatriz;
  int ** traspuesta;

  cout << "Introduzca las filas: ";
  cin >> F;
  cout << "Introduzca las columnas: ";
  cin >> C;

  Limpia();

  //INICIALIZACION ALEATORIA
  cout << "CREA MATRIZ ALEATORIA" << endl;
  matriz = Crea_Rellena_Aleatoriamente(F, C);
  Muestra_Matriz(matriz, F, C);

  //COPIA
  cout << "\nCOPIA MATRIZ" << endl;
  copia_matriz = Copia_Matriz(matriz, F, C);
  Muestra_Matriz(matriz, F, C);

  //SUBMATRIZ
  cout << "\nCREA SUBMATRIZ" << endl;
  int inicio_F, inicio_C, fin_F, fin_C;

  cout << "Introduce inicio y fin de fila: ";
  cin >> inicio_F >> fin_F;
  cout << "Introduce inicio y fin de columna: ";
  cin >> inicio_C >> fin_C;

  submatriz = Submatriz(matriz, inicio_F, inicio_C, fin_F, fin_C);
  Muestra_Matriz(submatriz, fin_F-inicio_F+1, fin_C-inicio_C+1);

  //ELIMINA FILA
  cout << "\nELIMINA FILA" << endl;
  int fila_borrar;
  int **matriz_f;

  cout << "\nFila a eliminar: ";
  cin >> fila_borrar;

  matriz_f = Elimina_Fila(matriz, F, C, fila_borrar);
  Muestra_Matriz(matriz_f, F-1, C);

  //ELIMINA COLUMNA
  cout << "\nELIMINA COLUMNA" << endl;
  int col_borrar;
  int **matriz_c;

  cout << "\nColumna a eliminar: ";
  cin >> col_borrar;

  matriz_c = Elimina_Columna(matriz, F, C, col_borrar);
  Muestra_Matriz(matriz_c, F, C-1);

  Limpia();

  //MATRIZ TRASPUESTA
  cout << "MATRIZ TRASPUESTA" << endl;
  traspuesta = Traspuesta(matriz, F, C);
  Muestra_Matriz(traspuesta, F, C);




  return 0;
}
