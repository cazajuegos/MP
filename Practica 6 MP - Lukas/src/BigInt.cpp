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
			size = obj.getSize() + 1;
			number = new int[size];
			for(int i = 0; i < size; i++)
				number[i] = obj.get(i - 1);
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

		void operator =(const BigInt&n1){
			size = n1.getSize() + 1;
			number = new int[size];
			for(int i = 0; i < size; i++)
				number[i] = n1.get(i - 1);
		}

		/* Overload */
		BigInt operator +(const BigInt&n1){
			BigInt max, min;
			if(getSize() > n1.getSize()){
				max = *this;
				min = n1;
			}else if(getSize() < n1.getSize()){
				max = n1;
				min = *this;
			}else{
				bool tbig = false;
				for(int i = 0; i < getSize() && !tbig; i++){
					if(n1.get(i) > get(i)){
						tbig = true;
					}
				}
				if(tbig){
					max = n1;
					min = *this;
				}else{
					max = *this;
					min = n1;
				}
			}
			int maxsize =  max.getSize(), fnsz = maxsize;
			int *smfin = new int[maxsize];

			int acarreo = 0;
			for(int i = 0; i < maxsize; i++){
				int sum;
				if(min.getSign() * max.getSign() < 0){
					sum = max.get(i) - min.get(i) + acarreo;
					acarreo = sum / 10;
					sum += -10 * acarreo;
				}else{
					sum = max.get(i) + min.get(i) + acarreo;
					acarreo = sum / 10;
				}
				smfin[i] = mod(abs(sum), 10);
			}

			fnsz += acarreo;
			BigInt suma(fnsz);
			suma.set(0, (1 - max.getSign()) / 2);

			for(int i = 0; i < fnsz; i++){
				suma.set(i + 1, smfin[i]);
			}
			if(acarreo == 1){
				suma.set(maxsize + 1, 1);
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
