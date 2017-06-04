#ifndef PAREJA_H
#define PAREJA_H

class Pareja{
private:
  int dato;
  int nveces;
public:
  Pareja();
  Pareja(int _dato, int _nveces);
  Pareja(const Pareja &p);
  int GetDato()const;
  int GetVeces()const;
  void incrementar(int i);
  void Mostrar() const;
};

class Precuencias{
  private:
    Pareja * parejas;
    int npares;
  public:
    Precuencias();
    Precuencias(const Precuencias &l);
    ~Precuencias();
    void AgregarValor(int dato, int veces);
    void Mostrar() const;
    void Limpiar_Pantalla();
  };

#endif
