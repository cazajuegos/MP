#ifndef BARQUITOS_H
#define BARQUITOS_H

class Barquitos{
	private:
		int **matrix;

		int rows;
		int cols;
		int boat_number;
		int golpeados;
	public:
		/* Constructors */
		Barquitos(int total_rows, int total_cols, int num_boats);

		Barquitos ( const Barquitos &obj);

		~Barquitos();

		void finish(bool&playing);
		/* Get methods */
		int getRows() const;
		int getCols() const;

		/* Main Methods */
		bool inner(int x, int y) const;
		bool isShot(int x, int y) const;
		/* get and set cell method */
		int get(int x, int y) const;
		void set(int x, int y, int val);
		int shot(int x, int y);
		bool setBoat(int x, int y, int s, char o);

		void showMatrix(bool all);
		void createBoard(int seed);

		void play();
		Barquitos& operator =(const Barquitos&n1);
};
#endif
