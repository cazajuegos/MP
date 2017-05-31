#include<iostream>
#include "Menu.h"
using namespace std;

int main(){
  Menu menu;
  cout << "Introduzca el titulo de su menu: ";
  char buffer[50];
  cin.getline(buffer, 50);
  menu.setTitle(buffer);
  cout << "Introduzca cada una de las opciones (* para terminar): ";
  cin.getline(buffer, 50);
  while(buffer[0] != '*'){
    menu.setOpcion(buffer);
    cout << "Introduzca cada una de las opciones (* para terminar): ";
    cin.getline(buffer, 50);
  }
  menu.show();
}
