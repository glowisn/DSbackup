/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//qsort example -using char

#include <iostream>
int comp_char (const void *a, const void *b){
  return (*(char*)a - *(char*)b);
}

int main(){
  char values[] = { 'n', 'i', 'b', 'c' };
  int n = sizeof(values) / sizeof(values[0]);
  qsort(values, n, sizeof(values[0]), comp_char);

  for (int i = 0; i < n ; i++)
    std::cout << values[i] << " ";

  return 0;
}
