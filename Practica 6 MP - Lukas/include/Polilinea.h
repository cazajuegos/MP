#ifndef POLILINEA_H
#define POLILINEA_H

class Punto{
  private:
    int x;
    int y;
  public:
    Punto();
    Punto(int i, int j);

    Punto(const Punto&n);
    int getX() const;
    int getY() const;

    bool operator ==(const Punto&n) const;

    void show();
};

class Polilinea{
  private:
    Punto *puntos;
    int total;
  public:
    /* Constructor/Destructor */
    Polilinea();
    ~Polilinea();

    Polilinea(const Polilinea&n);

    /* get/set */
    int getTotal() const;
    Punto getPunto(int i) const;

    void setPunto(const Punto&punto);

    /* overload */
    Polilinea& operator =(const Polilinea &p);

    /* main */
    void show();
};

#endif
