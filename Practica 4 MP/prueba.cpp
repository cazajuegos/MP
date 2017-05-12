#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  const int FIL = 2;
  const int COL = 3;

  int m[FIL][COL] = {{1,2,3},{4,5,6}};

  int x;
  int *ptr=&x;
  x=23;
  *ptr=40;

  cout << &x << " " << x << " y " << ptr << " " << *ptr << endl;

  int y, array[5]={1,2,3,4,5}, *ptrInt;

  ptrInt = &x;
  ptrInt = array;
  ptrInt = &array[0];

  cout << ptrInt << " " << *ptrInt << endl;

  int a;
  int *ptt=&a;
  int **pttt=&ptt;

  *(*pttt)=5;

  cout << a << " " << &a << " y " << ptt << " " << *ptt << " y " << pttt << " " << *(*pttt) << endl;

  int *p;

  p= &(m[0][0]);

  for(int i=0; i<FIL*COL; i++){
    cout << *(p+i) << " ";
  }

  return 0;
}
