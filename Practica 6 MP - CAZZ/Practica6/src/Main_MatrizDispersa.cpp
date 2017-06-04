#include <iostream>
#include <cstdlib>
#include "MatrizDispersa.h"

using namespace std;

int main(){
  MatrizDispersa m;
  m.Limpiar_Pantalla();
  cout << "---------------" << "\nMATRIZ DISPERSA\n" << "---------------" << endl;
  m.RellenaMatriz();
  m.Limpiar_Pantalla();
  cout << "-------------------------------------------------------------------------------" << endl;
  m.Muestra_Matriz();
  cout << "-------------------------------------------------------------------------------" << endl;
  m.Muestra_Valores();
  cout << "-------------------------------------------------------------------------------" << endl;

  return 0;
}
