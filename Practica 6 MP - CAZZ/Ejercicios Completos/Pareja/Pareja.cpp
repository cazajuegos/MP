#include <iostream>
#include <cstdlib>

using namespace std;

class Pareja{
private:
  int dato;
  int nveces;
public:
  Pareja(){
    dato = 0;
    nveces = 0;
  }

  Pareja(int _dato, int _nveces){
    dato = _dato;
    nveces = _nveces;
  }

  Pareja(const Pareja &p){
    dato = p.dato;
    nveces = p.nveces;
  }

  int GetDato()const { return dato;}
  int GetVeces()const {return nveces;}
  void incrementar(int i){ nveces += i; }
  void Mostrar() const{
    cout << "El numero " << dato << " se repite " << nveces << "." << endl;
  }
};

class Precuencias{
  private:
    Pareja * parejas;
    int npares;
  public:
    Precuencias(){
      parejas = new Pareja[0];
      npares = 0;
    }

    Precuencias(const Precuencias &l){
      npares = l.npares;
      parejas = new Pareja[npares];
      for(int i = 0; i < npares; i++){
        parejas[i] = l.parejas[i];
      }
    }

    ~Precuencias(){
      delete [] parejas;
    }

    void AgregarValor(int dato, int veces){
      int existe = -1;
      for(int i = 0; i < npares && existe < 0; i++){
        if(dato == parejas[i].GetDato()){
          existe = i;
        }
      }

      if(existe >= 0){
        parejas[existe].incrementar(veces);
      }else{
        Pareja* nuevo = new Pareja[npares + 1];
        for(int i = 0; i < npares; i++){
          nuevo[i] = Pareja(parejas[i]);
        }
        nuevo[npares] = Pareja(dato, veces);
        delete[] parejas;
        parejas = nuevo;
        npares = npares + 1;
      }
    }

    void Mostrar() const{
      cout << "Estas son las siguientes repeticiones:" << endl;
      for(int i = 0; i < npares; i++){
        parejas[i].Mostrar();
      }
    }

    void Limpiar_Pantalla(){ system("/usr/bin/clear");}

};

int main(){
  cout << "-----------" << "\nPAREJA\n" << "-----------" << endl;

  Precuencias secuencia;
  char *numero = new char[100];
  cout << "Introduzca el numero: ";
  cin.getline(numero, 100);

  int i = 0;
  while(numero[i] != '\0'){
    int n = numero[i] - '0', m = 1;
    while(numero[i + m] == numero[i]) m++;
    secuencia.AgregarValor(n, m);
    i += m;
  }
  secuencia.Mostrar();
  delete [] numero;

  return 0;
}
