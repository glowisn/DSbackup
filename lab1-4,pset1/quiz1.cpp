/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//quiz 1 : Fix a code

//Question 1 :What type of an error?
//2.a run-time error

#include <iostream>
using namespace std;

int main(){
  int *pi;
  pi = new int;
  *pi = 17;
  cout << "i = " << *pi << endl;
  delete pi;
  return 0;
}
