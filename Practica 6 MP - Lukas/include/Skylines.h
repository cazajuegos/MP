#ifndef SKYLINES_H
#define SKYLINES_H

class Skylines{
  private:
    double *abscisas;
    double *alturas;
    int n;
  public:
    /* Constructor/Destructor */
    Skylines();
    ~Skylines();

    Skylines(const Skylines&n);

    /* get/set */
    int getTotal() const;
    void setSkyline(double ini, double fin, double altura);

    /* overload */
    Skylines& operator =(const Skylines &p);

    /* main */
    void show() const;
    void copy(const Skylines& sk);
};

#endif
