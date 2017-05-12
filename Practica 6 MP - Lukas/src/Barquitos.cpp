#include<iostream>
using namespace std;

class Barquitos{
	private: 
		int **matrix;
		int num_rows;
		int num_cols;
	public:
		/* Constructors */
		Barquitos(int total_rows, int total_cols){
			matrix = new int*[total_rows];
			for(int j = 0; j < total_rows; j++){
				matrix[j] = new int[total_cols];
				for(int i = 0; i < num_cols; i++){
					matrix[j][i] = 9;
					cout << matrix[j][i];
				}
			}
			num_rows = total_rows;
			num_cols = total_cols;
		};
		/* Get methods */
		int getRows(){ return num_rows; };
		int getCols(){ return num_cols; };

		/*Barquitos(const Barquitos &copia){
			num_rows = copia.getRows();
			num_cols = copia.getCols();
			matrix = new int*[num_rows];
			for(int j = 0; j < num_rows; j++){
				matrix[j] = new int[num_cols];
				for(int i = 0; i < num_cols; i++){
					matrix[j][i] = copia.get(i, j);
				}
			}
		};*/

		/* Main Methods */
		bool inner(int x, int y){ return (x >= 0 && x < num_cols) && (y >= 0 && y < num_rows); };
		bool isShot(int x, int y){ return get(x,y) < 0; };
		/* get and set cell method */
		int get(int x, int y){ return inner(x, y) ? matrix[y][x] : 0;  };
		void set(int x, int y, int val){ if(inner(x, y)) matrix[y][x] = val; };
		void shot(int x, int y){ if(!isShot(x,y)) matrix[y][x] *= -1; };
		void setBoat(int x, int y, int s, char o){
			int ori = (o == 'h') ? 1 : -1;
			bool canPlace = true;
			for(int i = 0; i < s && canPlace; i++){
				if(!inner(x + i * (ori + 1) / 2 , y - i * (ori - 1) / 2 )) canPlace = false;
			}
			cout << canPlace << endl;
			if(canPlace){
				for(int i = 0; i < s && canPlace; i++){
					set(x + i * (ori + 1) / 2 , y - i * (ori - 1) / 2, s);
				}
			}else{
				cout << "Can't be placed";
			}
		}

		void showMatrix(){
			for(int j = 0; j < num_rows; j++){
				for(int i = 0; i < num_cols; i++){
					cout << matrix[j][i];
				}
				cout << endl;
			}
		};
};


int main(){
	
	Barquitos juego(10, 10);
	juego.setBoat(0, 0, 3, 'v');
	juego.showMatrix();
	
}
