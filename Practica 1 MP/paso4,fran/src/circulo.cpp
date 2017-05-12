#include<iostream>
#include<cmath>
#include "circulo.h"
\
using namespace std;

/**
 * Metodo para mostrar por pantalla los datos de un objeto.
 */
void Circulo::mostrar() const {
    // Formato de escritura del círculo: radio-(x,y)
    cout << radio << " - (" << centro.getX() << ", " << centro.getY() << ")" << endl;
}

/**
  * Metodo para preguntar los valores de los datos miembro al
  * usuario. Por implementar
  */
void Circulo::leerDatos(){
    // Se pide al usuario el valor del radio y del centro
    cout << "Introduzca radio: ";
    cin >> radio;
    
    // Se pide al usuario que introduzca las coordenadas del centro
    centro.leerDatos();
}

/**
 * Metodo para calcular el area de un circulo
 * @return 
 */
double Circulo::calcularArea() const {
    // Se calcula el area
    double area=2*M_PI*pow(radio,2);
    
    // Se devuelve el resultado
    return area;
}
