#include<iostream>
#include<string>
using namespace std;

class Barquitos{
	private:
		int **matrix;

		int rows;
		int cols;
		int boat_number;
		int golpeados;
	public:
		/* Constructors */
		Barquitos(int total_rows, int total_cols, int num_boats){
			matrix = new int*[total_rows];
			for(int j = 0; j < total_rows; j++){
				matrix[j] = new int[total_cols];
				for(int i = 0; i < total_cols; i++){
					matrix[j][i] = 9;
				}
			}
			rows = total_rows;
			cols = total_cols;
			boat_number = num_boats;
			golpeados = 0;
		};

		Barquitos ( const Barquitos &obj){
			rows = obj.getRows();
			cols = obj.getCols();
			boat_number = obj.getNumBarquitos();
			golpeados 	= 0;
			matrix = new int*[rows];
			for(int j = 0; j < rows; j++){
				matrix[j] = new int[cols];
				for(int i = 0; i < cols; i++){
					matrix[j][i] = obj.get(i, j);
				}
			}
		};

		~Barquitos(){
			for(int i = 0; i < rows; i++){
				delete[] matrix[i];
			}
			delete[] matrix;
		};

		void finish(bool&playing){
			showMatrix(true);
			golpeados = 0;
			playing = false;
		};
		/* Get methods */
		int getRows() const{ return rows; };
		int getCols() const{ return cols; };
		int getNumBarquitos() const{ return barquitos; };

		/* Main Methods */
		bool inner(int x, int y) const{ return (x >= 0 && x < cols) && (y >= 0 && y < rows); };
		bool isShot(int x, int y) const{ return get(x,y) < 0; };
		/* get and set cell method */
		int get(int x, int y) const{ return inner(x, y) ? matrix[y][x] : 0;  };
		void set(int x, int y, int val){ if(inner(x, y)) matrix[y][x] = val; };
		int shot(int x, int y){ if(!isShot(x,y)){ matrix[y][x] *= -1; return -matrix[y][x]; } else return -1; };
		bool setBoat(int x, int y, int s, char o){
			int ori = (o == 'h') ? 1 : -1;
			bool canPlace = true;
			int hor = (ori + 1) / 2, vrt = hor - 1;
			for(int i = 0; i < s && canPlace; i++){
				int ii = x + i * hor;
				int jj = y - i * vrt;
				if(!inner(ii, jj) && get(ii, jj) == 9) canPlace = false;
			}
			if(canPlace){
				for(int i = 0; i < s && canPlace; i++){
					set(x + i * hor, y - i * vrt, s);
				}
				golpeados += s;
			}
			return canPlace;
		};

		void showMatrix(bool all){
			char type;
			for(int j = 0; j < rows; j++){
				for(int i = 0; i < cols; i++){
					int cell = matrix[j][i];
					if(cell < 0){
						type = cell == -9 ? 'o' : '*';
					}else if(cell  == 9 || !all){
						type = '^';
					}else if(all){
						type = '0' + cell;
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

		void play(){
			int number;
			cout << "Introduzca la seed del juego: ";
			cin >> number;
			golpeados = 0;
			createBoard(number);
			string message;
			bool playing = true;
			while(playing){
				cout << "Quiere abrir el menu? (s/n): ";
				char menu;
				int option = 1;
				cin >> menu;
				if(menu == 's' || menu == 'S'){
					cout << "(1) Disparar " << endl << "(2) Ver mapa" << endl << "(3) Rendirse" << endl << "Seleccion: ";
					cin >> option;
				}

				if(option == 1){
					int i, j;
					cout << "Donde quiere disparar? [x, y]: ";
					cin >> i >> j;
					int cell = shot(i, j);
					if(cell < 0){
						message = "No puede volver a disparar donde ya ha disparado!";
					}else if(cell == 9){
						message = "Pum! Pof! Aguaa!";
					}else{
						message = "Le hemos dado!!";
						golpeados--;
					}
					cout << message << endl;
					if(golpeados <= 0){
						cout << "Ganaste!" << endl;
						finish(playing);
					}
				}else if(option == 2){
					showMatrix(false);
				}else if(option == 3){
					cout << "Esta seguro? (s/n)";
					cin >> menu;
					if(menu == 'S' || menu == 's'){
						finish(playing);
					}
				}
			}
		};
};


int main(){
	Barquitos juego(10, 10, 5);
	juego.play();
	Barquitos juego1(juego);
	juego1.play();

}
