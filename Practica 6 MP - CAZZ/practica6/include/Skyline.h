#ifndef SKYLINE_H
#define SKYLINE_H

class Skyline{
private:
  double * abscisas;
  double * alturas;
  int n;
  int n_altura;
public:
  Skyline();
  ~Skyline();
  void setSkyline(double inc_abscisa, double fin_abscisa, double altura);
  Skyline(const Skyline &s);
  void Muestra();
  void LimpiarPantalla();
};

#endif
