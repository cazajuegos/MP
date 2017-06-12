#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

class Valor{
private:
  double valor;
  int fila;
  int columna;
public:
  Valor();
  Valor(double _valor, int _fila, int _columna);
  Valor(const Valor &v);
  double getValor() const;
  int getFila() const;
  int getColumna() const;
};

class MatrizDispersa{
private:
  int nfilas;
  int ncolumnas;
  double **matriz;
  Valor * valores;
  int numeroValores;
public:
  MatrizDispersa();
    MatrizDispersa(const MatrizDispersa&n);
    ~MatrizDispersa();
    void CreaMatriz_Dinamica(int F, int C);
    void RellenaMatriz();
    void Muestra_Valores();
    void Muestra_Matriz();
    void Limpiar_Pantalla();
  };
  
#endif
