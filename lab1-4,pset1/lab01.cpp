/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//Lab 1 :Convert a C program to C++

#include <iostream>
using namespace std;

const int N = 40;

void sum(int d[], int n, int& p){
  p = 0;
  for(int i = 0; i < n; ++i) p = p + d[i];
}

int main(){
  int total = 0;
  int *data = new int[N];
  for(int i=0; i <N; ++i) data[i] = i;
  sum(data, N, total);
  cout << "total is " << total << endl;

  delete[] data;

  return 0;
}
