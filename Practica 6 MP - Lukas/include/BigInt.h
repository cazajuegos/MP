#ifndef BIGINT_H
#define BIGINT_H

class BigInt{
	private:
		int *number;
		int size;
	public:
		/* Constructors */
		BigInt();
		BigInt(int tam);
		BigInt( const BigInt &obj);

		~BigInt();

		/* Get methods */
		int getSize() const;

		/* Main Methods */
		int getSign() const;
		int get(int i) const;
		int set(int i, int v);

		void show();
		void read();

		/* Overload */
		BigInt operator +(const BigInt&n1);
		BigInt& operator =(const BigInt&n1);
};
#endif
