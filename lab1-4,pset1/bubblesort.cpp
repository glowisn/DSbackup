/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//lab04 : bubble sort

#include <iostream>
using namespace std;

int ascend(int &a, int &b){
  int temp;
  if(a > b){
    temp = a;
    a = b;
    b = temp;
  }
  return a, b;
}

int descend(int &a, int &b){
  int temp;
  if(a < b){
    temp = a;
    a = b;
    b = temp;
  }
  return a, b;
}

void bubblesort(int *list, int n, int (*compare)(int&,int&) = ascend){
  int i, j, temp;

  for(i = 0; i < n - 1; i++){
    for(j = 0; j < n - i - 1; j++){
        compare(list[j],list[j+1]);
      }
  }
}

void print_list(int *list, int N){
  for(int i = 0; i < N; i++)
    cout << list[i] << " ";
  cout << endl;
}

int main(){
  int list[] = { 2, 8, 1, 9, 5};
  int N = sizeof(list)/sizeof(list[0]);

  cout << "UNSORTED: " << endl;
  print_list(list, N);

  bubblesort(list, N);
  cout << "SORTED Up: " << endl;
  print_list(list, N);

  bubblesort(list, N, descend);
  cout << "SORTED Dn: " << endl;
  print_list(list, N);
  return 0;
}
