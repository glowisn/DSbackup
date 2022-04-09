/*On my honor, I pledge that I have neither received nor provided improper assistance in the
completion of this programming assignment. Signed: 정예찬*/

//quiz2 - mergesort

// 15 times -> 3 times
// E S , O R , M P
// only two elements are merging - continues all elements are merged


#include  <iostream>
#include <cassert>
using namespace std;

int isSorted(char *a, int i, int j){return a[i] <= a[j];}

void merge(char *a, char *aux, int lo, int mi, int hi){
	assert(isSorted(a,lo,mi));
	assert(isSorted(a,mi+1,hi));
	for(int k = lo; k <= hi; k++) aux[k] = a[k];

	int i = lo;
	int j = mi + 1;
	for(int k = lo; k <=hi; k++){
		if(i > mi)								a[k] = aux[j++];
		else if(j > hi)						a[k] = aux[i++];
		else if(aux[j] < aux[i])	a[k] = aux[j++];
		else											a[k] = aux[i++];
	}
	assert(isSorted(a,lo,hi));

}

void mergeSort(char *a, char *aux, int N, int lo, int hi){
	if(hi <= lo) return;
	int mi = lo + (hi - lo) / 2;
	mergeSort(a, aux, N, lo, mi);
	mergeSort(a, aux, N, mi+1,hi);
	merge(a, aux, lo, mi, hi);
}


int main() {
	char a[]={'M','E','R','G','E','S','O','R','T','E','X','A','M','P','L','E'};
	cout << "UNSORTED: "; for (auto x: a) cout << x; cout << endl;
	int N = sizeof(a) / sizeof(a[0]);
	char *aux = new char[N];
	mergeSort(a, aux, N, 0, N - 1);
	cout << " SORTED: "; for (auto x: a) cout << x; cout << endl;
}
