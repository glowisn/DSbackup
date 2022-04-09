// mergesort.cpp by idebtor@gmail.com
// A typical recursive implementation of mergesort
// using function template in C++.
// 2020.09.15  mergesort using template

/*
 On my honour, I pledge that I have neither received nor provided improper assistance in the
 completion of this assignment.
 Signed: _정예찬___ Section: _컴퓨터구조_01_ Student Number: ___21700663______
*/

#include <iostream>
#include <cassert>
using namespace std;

#ifdef DEBUG
#define DPRINT(func) func;
#else
#define DPRINT(func) ;
#endif

template <typename T>
int isSorted(T *a, int i, int j){return a[i] <= a[j];}
bool less(int a, int b) { return a - b < 0; }

template <typename T>
void merge(T *a, T *aux, int lo, int mi, int hi) {
    assert(isSorted(a, lo, mi));
    assert(isSorted(a, mi+1, hi));
    for(int k = lo; k <= hi; k++) aux[k] = a[k];

    int i = lo;
    int j = mi + 1;
    for (int k = lo; k <= hi; k++) {
        if      (i > mi)          a[k] = aux[j++];     // A is exhausted, take B[j]
        else if (j > hi)          a[k] = aux[i++];     // B is exhausted, take A[i]
        else if (aux[j] < aux[i]) a[k] = aux[j++];     // B[j] <  A[i], take B[j]
        else                      a[k] = aux[i++];     // A[i] <= B[j], take A[i]
    }

}

template <typename T>
void mergeSort(T *a, T *aux, int N, int lo, int hi) {
    if(hi <= lo)return;
    int mi = (lo + hi) / 2;
    mergeSort(a, aux, N, lo, mi);
    mergeSort(a, aux, N, mi+1, hi);
    if(::less(a[mi],a[mi+1])) return;
    merge(a, aux, lo, mi, hi);
}

template <typename T>
void mergeSort(T *a, int N) {
  T *aux = new T[N];

  mergeSort(a, aux, N, 0, N - 1);
	delete[] aux;
}

#if 1
int main() {
    char list[] = {'M','E','R','G','E','S','O','R','T','E','X','A','M','P','L','E'};
		//int list[] = { 1, 4, 5, 2, 10, 3 };
    int N = sizeof(list) / sizeof(list[0]);
    cout << "UNSORTED: ";
    for (auto x: list) cout << x << " "; cout << endl;

    mergeSort(list, N);

    cout << "  SORTED: ";
    for (auto x: list) cout << x << " "; cout << endl;
}
#endif
