#ifndef UTILIDADES_H
#define UTILIDADES_H

#include "punto.h"
#include "circulo.h"

double calcularDistancia(Punto, Punto);
Punto calcularPuntoMedio(Punto, Punto);
double calcularDistancia(Circulo, Circulo);
bool comprobarInterior(Punto, Circulo);

#endif