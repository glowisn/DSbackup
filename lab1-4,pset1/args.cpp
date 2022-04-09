/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//Lab 3 : C++ class: string, and vector<stinrg>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> args_to_strVector(int argc, char **argv);
string *args_to_strArray(int argc, char **argv);
void print_args(vector<string> args);
void print_args(string *args, int argc);

int main(const int argc, char** argv){
  cout << "You entered: " << argc << " arguments:"<< endl;  //print number of argc

  vector<string> s_vector;
  s_vector = args_to_strVector(argc, argv);
  print_args(s_vector); //print vector

  string *s_string = new string[argc];
  s_string = args_to_strArray(argc, argv);
  print_args(s_string, argc);
  delete[] s_string;

  return 0;
}
