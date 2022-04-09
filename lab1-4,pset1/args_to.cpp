/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//Lab 3 : C++ class: string, and vector<stinrg>

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> args_to_strVector(int argc, char **argv){
  vector<string> s;
  for(int i = 0; i < argc ; i++){
    s.push_back(argv[i]);
  }

  return s;
}

string *args_to_strArray(int argc, char **argv){
  string *s = new string[argc];
  for(int i = 0; i < argc; i++){
    s[i] = argv[i];
  }

  return s;
}

void print_args(vector<string> args){
  for(int i = 0; i < args.size() ; i++)
    cout << "vectors: " <<  args[i] << endl;
}

void print_args(string *args, int argc){
  for(int i =0; i < argc; i++){
    cout << "strings: " << args[i] << endl;
  }
}
