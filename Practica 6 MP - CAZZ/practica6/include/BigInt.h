#ifndef BIGINT_H
#define BIGINT_H

class BigInt{
private:
  int *numero, tam;

public:
  BigInt();
  BigInt(int tm);
  ~BigInt();
  BigInt(const BigInt &b);
  void Lee_Numero();
  void Muestra();
  BigInt Suma(const BigInt &b);
};

#endif
