#include<iostream>
#include"BigInt.h"
using namespace std;

int main(){
	BigInt number1;
	number1.read();
	BigInt number2;
	number2.read();

	BigInt number3 = number1 + number2;
	cout << "La suma de ambos numeros es: ";
	number3.show();
	cout << endl;
}
