#include <iostream>
#include <cstdlib>

using namespace std;

class Skyline{
private:
  double * abscisas;
  double * alturas; //La ultima sera 0
  int n;
  int n_altura;
public:
  Skyline(){
    abscisas = new double[0];
    alturas = new double [0];
    n = 0;
    n_altura = 0;
  }

  ~Skyline(){
    delete [] abscisas;
    delete [] alturas;
  }

  void setSkyline(double inc_abscisa, double fin_abscisa, double altura){
    double *newabscisas  = new double[n + 2];
    double *newalturas   = new double[n + 1];

    for(int i = 0; i < n; i++){
      newabscisas[i] = abscisas[i];
      newalturas[i] = alturas[i];
    }

    newabscisas[n] = inc_abscisa;
    newabscisas[n + 1] = fin_abscisa;
    newalturas[n] = altura;

    delete [] abscisas;
    delete [] alturas;

    abscisas = newabscisas;
    alturas = newalturas;

    n += 2;
  }

  Skyline(const Skyline &s){
    n = s.n;
    n_altura = s.n_altura;
    abscisas = new double[n];
    alturas = new double[n];
    for(int i = 0; i < n; i++){
      abscisas[i] = s.abscisas[i];
      alturas[i] = s.alturas[i];
    }
  }

  void Muestra(){
    cout << "----------" << endl;
    cout << "Edificios: " << endl;
    cout << "----------" << endl;
    for(int i = 0; i < n; i+=2){
      cout << "[" << abscisas[i] << ", " << abscisas[i + 1] << "] = " << alturas[i] << "." << endl;
    }
  }

  void LimpiarPantalla(){
    system("/usr/bin/clear");
  }

};

int main(){
  Skyline sky;
  double inc_abscisa, fin_abcisa, altura;
  sky.LimpiarPantalla();

  cout << "--------" << "\nSKYLINE\n" << "--------" << endl;

  cout << "Introduzca un intervalo de abscisas: ";
  cin >> inc_abscisa >> fin_abcisa;
  cout << "Introduzca la altura: ";
  cin >> altura;
  while(altura != 0){
    sky.setSkyline(inc_abscisa, fin_abcisa, altura);
    cout << "--------------------------------------------"<< endl;
    cout << "Introduzca un intervalo de abscisas: ";
    cin >> inc_abscisa >> fin_abcisa;
    cout << "Introduzca la altura: ";
    cin >> altura;
  }
  sky.LimpiarPantalla();
  sky.Muestra();
  return 0;
}
