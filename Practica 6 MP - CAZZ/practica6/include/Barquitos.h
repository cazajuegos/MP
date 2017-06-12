#ifndef BARQUITOS_H
#define BARQUITOS_H

class Barquitos{
private:
  int **tablero;
  int filas;
  int columnas;

public:
    Barquitos(int _filas, int _columnas);
    ~Barquitos();
    Barquitos(const Barquitos &b);
    void Muestra();
    bool Limites(int a, int b);
    void Poner_Barcos(int x, int y, int tam, char posicion);
    void Dispara();
    void Limpiar();
};

#endif
