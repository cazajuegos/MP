#include<iostream>
using namespace std;

class Barquitos{
	private:
		int **matrix;
		int rows;
		int cols;
		int boat_number;
	public:
		/* Constructors */
		Barquitos(int total_rows, int total_cols, int boats){
			matrix = new int*[total_rows];
			for(int j = 0; j < total_rows; j++){
				matrix[j] = new int[total_cols];
				for(int i = 0; i < total_cols; i++){
					matrix[j][i] = 9;
				}
			}
			rows = total_rows;
			cols = total_cols;
			boat_number = boats;
		};
		/* Get methods */
		int getRows(){ return rows; };
		int getCols(){ return cols; };

		/*Barquitos(const Barquitos &copia){
			rows = copia.getRows();
			cols = copia.getCols();
			matrix = new int*[rows];
			for(int j = 0; j < rows; j++){
				matrix[j] = new int[cols];
				for(int i = 0; i < cols; i++){
					matrix[j][i] = copia.get(i, j);
				}
			}
		};*/

		/* Main Methods */
		bool inner(int x, int y){ return (x >= 0 && x < cols) && (y >= 0 && y < rows); };
		bool isShot(int x, int y){ return get(x,y) < 0; };
		/* get and set cell method */
		int get(int x, int y){ return inner(x, y) ? matrix[y][x] : 0;  };
		void set(int x, int y, int val){ if(inner(x, y)) matrix[y][x] = val; };
		bool shot(int x, int y){ if(!isShot(x,y)){ matrix[y][x] *= -1; return true; } else return false; };
		bool setBoat(int x, int y, int s, char o){
			int ori = (o == 'h') ? 1 : -1;
			bool canPlace = true;
			for(int i = 0; i < s && canPlace; i++){
				int ii = x + i * (ori + 1) / 2;
				int jj = y - i * (ori - 1) / 2;
				if(!inner(ii, jj) && get(ii, jj) == 9) canPlace = false;
			}
			if(canPlace){
				for(int i = 0; i < s && canPlace; i++){
					set(x + i * (ori + 1) / 2 , y - i * (ori - 1) / 2, s);
				}
			}
			return canPlace;
		};

		void showMatrix(bool all){
			char type;
			for(int j = 0; j < rows; j++){
				for(int i = 0; i < cols; i++){
					int cell = matrix[j][i];
					if(cell < 0){
						type = 'o';
					}else if(cell  == 9){
						type = '^';
					}else{
						type = 254;
					}
					cout << type;
				}
				cout << endl;
			}
		};

		void createBoard(int seed){
			int i = 0, j = 0;
			while(j < boat_number){
				int ii 		= ((i * 341 + 111) * 7 + seed) % cols;
				int jj 		= ((i * 107 + 287) * 11 + seed) % rows;
				int size 	= (((i + 173) * 17 + seed * 11) % 5) + 2;
				char ornt = (bool)(((i + 173) * 17 + seed * 11) % 2) ? 'v' : 'h';
				if(setBoat(ii, jj, size, ornt)){
					j++;
				}else if(setBoat(ii, jj, size, ornt == 'v' ? 'h' : 'v')){
					j++;
				}
				i++;
			}
		};
};


int main(){
	int number;
	cout << "Introduzca la seed del juego: ";
	cin >> number;
	Barquitos juego(10, 10, 5);
	juego.createBoard(number);
	juego.showMatrix(true);
	while()

}
