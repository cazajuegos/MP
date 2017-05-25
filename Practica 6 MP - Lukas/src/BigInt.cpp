#include<iostream>
#include<string>
using namespace std;

int mod(int a, int b){ return ((a%b)+b)%b; };
int abs(int a){ return (a < 0 ? -a : a); };
class BigInt{
	private:
		int *number;
		int size;
	public:
		/* Constructors */
		BigInt(){
			size = 1;
			number = new int[size];
			number[0] = 0;
		};

		BigInt(int tam){
			size = tam + 1;
			number = new int[tam + 1];
			number[0] = 0;
		};


		BigInt( const BigInt &obj){
			size = obj.getSize();
			number = new int[size];
			for(int i = 0; i < size; i++)
				number[i] = obj.get(i);
		};

		~BigInt(){
			delete[] number;
		};

		/* Get methods */
		int getSize() const{ return size - 1; };

		/* Main Methods */
		int getSign() const{ return 1-2*number[0]; };
		int get(int i) const{ return (i + 1 < size) ? number[i + 1] : 0; }
		int set(int i, int v){ number[i] = v; }

		void show(){
			cout << ((bool)number[0] ? '-' : '+');
			for(int i = 1; i < size; i++){
				cout << number[size - i];
			}
		}

		void read(){
			size = 0;
			char read[100];
			cout << "Write the number: ";
			cin.getline(read, 100);
			int total = 0;
			bool isNumber = true;
			while(isNumber){ total++; if(read[total] < '0' || read[total] > '9') isNumber = false; }
			int signo = -1, noSign;
			if (read[0] == '-'){ signo = 1; noSign = 0; }
			else if (read[0] == '+'){ signo = 0; noSign = 0; }
			else if(read[0] >= '0' && read[0] <= '9'){ signo = 0; noSign = 1; }
			else{
				cerr << "No se ha introducido un numero correcto." << '\n';
				return;
			}
			total += noSign;
			int* fnumb = new int[total];
			fnumb[0] = signo;
			size = total;
			for(int i = 1; i < total; i++){
				fnumb[i] = read[total - noSign - i] - '0';
			}
			delete[] number;
			number = fnumb;
		}

		/* Overload */
		BigInt operator +(const BigInt&n1){
			int max = getSize() >= n1.getSize() ? getSize() : n1.getSize(), fnsz = max;
			int *smfin = new int[max];

			int acarreo = 0;
			int sign;
			if(getSign() * n1.getSign() > 0){ // Both have the same sign.
				sign = (1-getSign())/2;
				for(int i = 0; i < max; i++){
					int sum = get(i) + n1.get(i) + acarreo;
					smfin[i] = sum % 10;
					acarreo = sum / 10;
				}
				fnsz += acarreo;
			}

			BigInt suma(fnsz);
			suma.set(0, sign);
			for(int i = 0; i < fnsz; i++){
				suma.set(i + 1, smfin[i]);
			}
			if(acarreo == 1){
				suma.set(max + 1, 1);
			}

			delete[] smfin;
			return suma;
		}
};

int main(){
	BigInt number1;
	number1.read();
	BigInt number2;
	number2.read();

	BigInt number3 = number1 + number2;
	cout << "La suma de ambos numeros es: ";
	number3.show();
}
