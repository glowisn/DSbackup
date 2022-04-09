/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//fps.cpp : Using an Array of Function Pointers

#include <iostream>
using namespace std;

int fun(int x, int y){
  return x * 2 + y;
}

int foo(int x, int y){
  return x + y * 2;
}

int add(int x, int y){
  return x + y;
}

void op_print(int (*op)(int, int),int a, int b){
  cout << "op(): " << op(a,b) << endl;
}

int main(){
  //fps[] is an array of fp

  int (*fps[])(int, int) = {fun, foo, add};
  int N = sizeof(fps) / sizeof(fps[0]);
  for(int i = 0; i < N; i++){
    //cout << "fp(): " << fps[i](2,3) << endl;
    op_print(fps[i], 2 , 3);
  }
}
