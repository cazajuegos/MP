#include<iostream>
#include<string>
using namespace std;

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
		int getSize() const{ return size; };

		/* Main Methods */
		int get(int i) const{ return number[i]; }

		void show(){
			cout << ((number[0] == '1') ? '-' : '\n');
			for(int i = 1; i < size; i++){
				cout << number[i]<<  endl;
			}
		}

		void read(){
			char k;
			cout << "Is the number positive?(y/o): ";
			cin >> k;
			int positive = 1;
			if(k == 'y' || k == 'Y') positive = 0;

			size = 0;
			int read[100];
			cout << "Write the number(negative to finish): ";

			int r;
			cin >> r;
			while(r >= 0){
				read[size] = r;
				size++;
				cin >> r;
				cout << r << " - " << size << endl;
			}

			int* fnumb = new int[size + 1];
			fnumb[0] = positive;
			for(int i = 0; i < size; i++){
				fnumb[i+1] = number[size - 1 - i];
			}
			cout << size;
			number = fnumb;
		}
};


int main(){
	BigInt *number1 = new BigInt();
	number1->read();
	number1->show();

	delete number1;
}
