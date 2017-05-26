#include<iostream>
using namespace std;

class Matrix1{
  private:
    int **matrix;
    int cols, rows;
  public:
    Matrix1(int num_cols, int num_rows):cols(num_cols), rows(num_rows){
      matrix = new int*[rows];
      for(int i = 0; i < rows; i++){
        matrix[i] = new int[cols];
      }
    }
    ~Matrix1(){
      remove();
    }

    void set(int x,int y, int v){ matrix[y][x] = v; }
    int get(int x, int y) const{ return matrix[y][x]; }
    int getCols() const{ return cols; }
    int getRows() const{ return rows; }

    void remove(){
      for(int i = 0; i < rows; i++){
        delete[] *(matrix + i);
      }
      delete[] matrix;
    }

    void fill(){
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          cout << "Introduzca (" << i << ", " << j << "): ";
          cin >> matrix[j][i];
        }
      }
    }

    void random_fill(){
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          matrix[j][i] = 17/((((i + j) * 435) % 17) + 1);
        }
      }
    }

    void show(){
      cout << "La matriz siguiente es: " << endl;
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          cout << matrix[j][i] << " ";
        }
        cout << endl;
      }
    }

    Matrix1 copy(){
      Matrix1 copia(cols, rows);
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          copia.set(i, j, get(i, j));
        }
      }
      return copia;
    }

    Matrix1 submatrix(int i0, int j0, int i1, int j1){
      Matrix1 sub(i1 - i0 + 1, j1 - j0 + 1);
      for(int j = j0; j <= j1; j++){
        for(int i = i0; i <= i1; i++){
          sub.set(i - i0, j - j0, get(i, j));
        }
      }
      return sub;
    }

    Matrix1 removeRow(int a){
      Matrix1 sub(cols, rows - 1);
      for(int j = 0, m = 0; j < rows; j++){
        if(j == a){
          j++;
          m++;
        }
        for(int i = 0; i < cols; i++){
          sub.set(i, j - m, get(i, j));
        }
      }
      return sub;
    }

    Matrix1 removeCol(int a){
      Matrix1 sub(cols - 1, rows);
      for(int j = 0, m = 0; j < cols; j++){
        if(j == a){
            j++;
            m++;
        }
        for(int i = 0; i < rows; i++){
          sub.set(j - m, i, get(j, i));
        }
      }
      return sub;
    }

    Matrix1 transpose(){
      Matrix1 transpose(rows, cols);
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          transpose.set(j, i, get(i, j));
        }
      }
      return transpose;
    }

    Matrix1 flip(){
      Matrix1 flipped(cols, rows);
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          flipped.set(i, cols - j - 1, get(i, j));
        }
      }
      return flipped;
    }

    void operator =(const Matrix1&mt){
	cols = mt.getCols();
	rows = mt.getRows();	
	matrix = new int*[rows];
	for(int j = 0; j < rows; j++){
		matrix[j] = new int[cols];
		for(int i = 0; i < cols; i++){
			matrix[j][i] = mt.get(i, j);
		}
	}
    }
};

class Matrix2{
  private:
    int *matrix;
    int cols, rows;
  public:
    Matrix2(int num_cols, int num_rows):cols(num_cols), rows(num_rows){
      matrix = new int[rows * cols];
    }
    ~Matrix2(){
			remove();
		}

    void set(int x,int y, int v){ matrix[y * cols + x] = v; }
    int get(int x, int y) const{ return matrix[y * cols + x]; }
    int getCols() const{ return cols; }
    int getRows() const{ return rows; }

    void remove(){
      delete[] matrix;
    }

    void fill(){
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          cout << "Introduzca (" << i << ", " << j << "): ";
          cin >> matrix[j * cols + i];
        }
      }
    }

    void random_fill(){
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          matrix[j * cols + i] = 17/((((i + j) * 435) % 17) + 1);
        }
      }
    }

    void show(){
      cout << "La matriz siguiente es: " << endl;
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          cout << matrix[j * cols + i] << " ";
        }
        cout << endl;
      }
    }

    Matrix2 copy(){
      Matrix2 copia(cols, rows);
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          copia.set(i, j, get(i, j));
        }
      }
      return copia;
    }

    Matrix2 submatrix(int i0, int j0, int i1, int j1){
      Matrix2 sub(i1 - i0 + 1, j1 - j0 + 1);
      for(int j = j0; j <= j1; j++){
        for(int i = i0; i <= i1; i++){
          sub.set(i - i0, j - j0, get(i, j));
        }
      }
      return sub;
    }

    Matrix2 removeRow(int a){
      Matrix2 sub(cols, rows - 1);
      for(int j = 0, m = 0; j < rows; j++){
        if(j == a){
          j++;
          m++;
        }
        for(int i = 0; i < cols; i++){
          sub.set(i, j - m, get(i, j));
        }
      }
      return sub;
    }

    Matrix2 removeCol(int a){
      Matrix2 sub(cols - 1, rows);
      for(int j = 0, m = 0; j < cols; j++){
        if(j == a){
            j++;
            m++;
        }
        for(int i = 0; i < rows; i++){
          sub.set(j - m, i, get(j, i));
        }
      }
      return sub;
    }

    Matrix2 transpose(){
      Matrix2 transpose(rows, cols);
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          transpose.set(j, i, get(i, j));
        }
      }
      return transpose;
    }

    Matrix2 flip(){
      Matrix2 flipped(cols, rows);
      for(int j = 0; j < rows; j++){
        for(int i = 0; i < cols; i++){
          flipped.set(i, cols - j - 1, get(i, j));
        }
      }
      return flipped;
    }
    void operator =(const Matrix2&mt){
	cols = mt.getCols();
	rows = mt.getRows();	
	matrix = new int[rows * cols];
	for(int i = 0; i < rows * cols; i++){
		matrix[i] = mt.get(i/rows, i%cols);
	}
    }
};

Matrix2 toMatrix1(Matrix2 matriz){
  int cols = matriz.getCols(), rows = matriz.getRows();
  Matrix2 matriz1(cols, rows);
  for(int j = 0; j < rows; j++){
    for(int i = 0; i < cols; i++){
      matriz1.set(i, j, matriz.get(i, j));
    }
  }
  return matriz1;
}

Matrix1 toMatrix2(Matrix2 matriz){
  int cols = matriz.getCols(), rows = matriz.getRows();
  Matrix1 matriz1(cols, rows);
  for(int j = 0; j < rows; j++){
    for(int i = 0; i < cols; i++){
      matriz1.set(i, j, matriz.get(i, j));
    }
  }
  return matriz1;
}

int main(int total, char **str){
  Matrix1 matriz0(3, 3);
  matriz0.fill();
  matriz0.show();
  Matrix1 flip1 = matriz0.submatrix(0, 0, 1, 1);
  flip1.show();
  Matrix1 transpose = matriz0.transpose();
  transpose.show();

  Matrix2 matriz1(3, 3);
  matriz1.fill();
  matriz1.show();
  Matrix2 flip2 = matriz1.submatrix(0, 0, 1, 1);
  flip2.show();
}
