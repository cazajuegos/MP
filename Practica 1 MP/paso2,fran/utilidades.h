#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "punto.h"
#include "circulo.h"

//PUNTO
void Punto::mostrar() const;
void Punto::leerDatos();
double calcularDistancia(Punto p1, Punto p2);
Punto calcularPuntoMedio(Punto p1, Punto p2);

//CIRCULO
void Circulo::mostrar() const;
void Circulo::leerDatos();
double Circulo::calcularArea();
double calcularDistancia(Circulo c1, Circulo c2);
bool comprobarInterior(Punto p, Circulo c);

#endif
