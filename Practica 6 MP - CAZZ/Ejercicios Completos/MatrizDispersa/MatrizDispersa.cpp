#include <iostream>
#include <cstdlib>

using namespace std;

class Valor{
private:
  double valor;
  int fila;
  int columna;
public:
  Valor(){
    valor = 0;
    fila = 0;
    columna = 0;
  }

  Valor(double _valor, int _fila, int _columna){
    valor = _valor;
    fila = _fila;
    columna = _columna;
  }

  Valor(const Valor &v){
    valor = v.valor;
    fila = v.fila;
    columna = v.columna;
  }

  double getValor() const{
    return valor;
  }

  int getFila() const{
    return fila;
  }

  int getColumna() const{
    return columna;
  }

};

class MatrizDispersa{
private:
  int nfilas;
  int ncolumnas;
  double **matriz;
  Valor * valores;
  int numeroValores;
public:
  MatrizDispersa(){
    nfilas = 0;
    ncolumnas = 0;
    valores = new Valor[0];
    numeroValores = 0;
  }

  MatrizDispersa(const MatrizDispersa&n){
    nfilas = n.nfilas;
    ncolumnas = n.ncolumnas;
    numeroValores = n.numeroValores;
    valores = new Valor[numeroValores];
    for(int i = 0; i < numeroValores; i++){
      valores[i] = n.valores[i];
    }
  }

  ~MatrizDispersa(){
    for(int i = 0; i < nfilas; i++){
      delete [] matriz[i];
    }
    delete [] matriz;
    delete [] valores;
  }

  void CreaMatriz_Dinamica(int F, int C){
    matriz = new double *[F];
    for(int i = 0; i < F; i++){
      matriz[i] = new double[C];
    }
  }

  void RellenaMatriz(){
    int tam = 0, tam1 = 0;
    cout << "Introduzca el numero de filas: ";
    cin >> nfilas;
    cout << "Introduzca el numero de columnas: ";
    cin >> ncolumnas;
    CreaMatriz_Dinamica(nfilas, ncolumnas);

    for(int i = 0; i < nfilas; i++){
      for(int j = 0; j < ncolumnas; j++){
        cout << "Valor (" << i << "," << j << "): ";
        cin >> matriz[i][j];
        tam++;
      }
      cout << endl;
    }

    valores = new Valor[tam];
    for(int i = 0; i < nfilas; i++){
      for(int j = 0; j < ncolumnas; j++){
        if(matriz[i][j] != 0.0){
          Valor* val = new Valor(matriz[i][j], i, j);
          valores[tam1++] = *val;
	  delete [] val;
        }
      }
    }
    numeroValores = tam1;
  }

  void Muestra_Valores(){
    cout << "VALORES" << endl;
    for(int i = 0; i < numeroValores; i++){
      cout << "Fila: " << valores[i].getFila() << ", Columna: " << valores[i].getColumna() << ", Valor: " <<
      valores[i].getValor() << endl;
    }
  }

  void Muestra_Matriz(){
    cout << "MATRIZ" << endl;
    for(int i = 0; i < nfilas; i++){
      for(int j = 0; j < ncolumnas; j++){
        cout << "[" << matriz[i][j] << "]";
      }
      cout << endl;
    }
  }

  void Limpiar_Pantalla(){
    system("/usr/bin/clear");
  }

};

int main(){
  MatrizDispersa m;
  m.RellenaMatriz();
  m.Limpiar_Pantalla();
  cout << "-------------------------------------------------------------------------------" << endl;
  m.Muestra_Matriz();
  cout << "-------------------------------------------------------------------------------" << endl;
  m.Muestra_Valores();
  cout << "-------------------------------------------------------------------------------" << endl;

  return 0;
}
