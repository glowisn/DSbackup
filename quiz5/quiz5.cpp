/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//Quiz5 - struct

#include  <iostream>
using namespace std;

struct Car{
	int age;
	string tag;
};

int main(){
	Car ur = {25, "cat"};
	Car* my = new Car{20, "sky"};
	Car* we = &ur;
	ur.tag = "hat";
	cout << we->tag << endl;
	delete my;
}
