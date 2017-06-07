/*16. Realice un programa que calcule la descomposicion en factores primos de
un numero entero.

Por ejemplo: 20 = 2*2*5.
*/

#include<iostream>
#include<curses.h>

using namespace std;

int main(){
	int numero;

	cout<<"Digite un numero: ";
	cin>>numero;

	cout<<"\nDescomponiendo en factores primos: ";
	for(int i=2;numero>1;i++){
		while(numero%i==0){
			cout<<i<<" ";
			numero /= i;
		}
	}

	cout<<"\n";
	getch();
	return 0;
}
