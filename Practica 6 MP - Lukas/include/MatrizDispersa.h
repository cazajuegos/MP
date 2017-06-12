#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H

class Valor{
  private:
    int fila;
    int columna;
    double valor;
  public:
    Valor();
    Valor(const Valor&c);
    Valor(int f, int c, double v);
    int getFila() const;
    int getColumna() const;
    double getValor() const;
};

class MatrizDispersa{
  private:
    int nfilas;
    int ncolumnas;
    Valor *valores;
    int numerovalores;
  public:
    /* Constructor/Destructor */
    MatrizDispersa();
    MatrizDispersa(const MatrizDispersa&n);

    ~MatrizDispersa();

    /* Overload */
    MatrizDispersa& operator =(const MatrizDispersa &n);

    /* Main */
    Valor* get(int i) const;
    void show() const;
    void copia(const MatrizDispersa& n);
    void create();
};

#endif
