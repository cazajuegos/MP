#include <iostream>

using namespace std;

class Punto{
private:
  int x, y;
public:
  Punto(){
    x = 0;
    y = 0;
  }

  Punto(int _x, int _y){
    x = _x;
    y = _y;
  }

  Punto(const Punto &l){
    x = l.x;
    y = l.y;
  }

  int getX() const{
    return x;
  }

  int getY() const{
    return y;
  }

};

class Polilinea{
private:
  Punto *p;
  int num;
public:
  Polilinea(){
    num = 0;
    p = new Punto[0];
  }

  ~Polilinea(){
    delete [] p;
  }

  Polilinea(const Polilinea &l){
    num = l.num;
    p = new Punto[num];
    for(int i = 0; i < num; i++){
      p[i] = l.p[i];
    }
  }

  void Aniade(const Punto &p1){
    Punto* sobre = new Punto[num + 1];
    for(int i = 0; i < num; i++){
      sobre[i] = Punto(p[i]);
    }
    sobre[num] = Punto(p1);
    num++;
    delete[] p;
    p = sobre;
  }

  void Mostrar(){
    for(int i = 0; i < num; i++){
      cout << "(x): " << p[i].getX() << " (y): " << p[i].getY() << endl;
    }
  }

};



int main(){
  Polilinea poli;
  Punto p1;
  int x, y;
  char respuesta;


  cout << "¿Desea introducir Puntos a la Polilinea(Y/N)? ";
  cin >> respuesta;

  while(toupper(respuesta) != 'N'){
    cout << "Introduzca (x): ";
    cin >> x;
    cout << "Introduzca (y): ";
    cin >> y;
    p1 = Punto(x, y);
    poli.Aniade(p1);
    cout << "\n¿Desea seguir añadiendo mas puntos(Y/N)? ";
    cin >> respuesta;
  }

  system("/usr/bin/clear");

  cout << "POLILINEA: " << endl;
  poli.Mostrar();

  return 0;
}
