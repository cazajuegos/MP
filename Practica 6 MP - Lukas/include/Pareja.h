#ifndef PAREJA_H
#define PAREJA_H

class Pareja{
  private:
    int dato;
    int nveces;
  public:
    Pareja();
    Pareja(int d, int n);
    Pareja(const Pareja& n);
    void incrementar(int i);
    int getDato() const;
    void show() const;
};

class Precuencia{
  private:
    Pareja *parejas;
    int npares;
  public:
    /* Constructor/Destructor */
    Precuencia();
    ~Precuencia();

    Precuencia(const Precuencia&n);

    /* get/set */
    int getTotal() const;
    void setPareja(int dato, int veces);

    /* overload */
    Precuencia& operator =(const Precuencia &p);

    /* main */
    void show() const;
    void copy(const Precuencia& sk);
};

#endif
