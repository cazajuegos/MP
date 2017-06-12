#ifndef POLILINEA_H
#define POLILINEA_H

class Punto{
private:
  int x, y;
public:
  Punto();
  Punto(int _x, int _y);
  Punto(const Punto &l);
  int getX() const;
  int getY() const;
};

class Polilinea{
private:
  Punto *p;
  int num;
public:
  Polilinea();
  ~Polilinea();
  Polilinea(const Polilinea &l);
  void Aniade(const Punto &p1);
  void Mostrar();
};

#endif
