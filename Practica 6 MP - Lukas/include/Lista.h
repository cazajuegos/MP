#ifndef LISTA_H
#define LISTA_H

class Celda{
  private:
    double info;
    Celda* sig;
  public:
    Celda();
    Celda(const Celda&c);
    Celda(double inf, Celda* n1);

    Celda* getSiguiente() const;

    void setSiguiente(Celda *n);
    void show() const;
};

class Lista{
  private:
    Celda* primero;
  public:
    /* Constructor/Destructor */
    Lista();
    Lista(const Lista&n);

    ~Lista();

    Celda* getPrimero() const;
    void setPrimero(Celda *n);

    /* Overload */
    Lista operator +(const Lista &n);
    Lista& operator =(const Lista &n);
    void operator [](const int n);

    /* Main */
    void show() const;
    void create();
};

#endif
