#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define db(a) printf("%s\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/*
use the base parameter wisely
mega complexity
= 3*n*(max digits in base)
*/

void countSort(int * arr, int n, int place, int base){
	// sort a/c a particular digit
	int op[n], i, count[base];

	for (i=0; i<base; i++)
		count[i] = 0;
	for (i=0; i<n; i++)
		count[ (arr[i]/place) % base ]++;
	for (i=1; i<base; i++)
		count[i] += count[i-1];
	for (i=n-1; i>=0; i--){
		op[ count[ (arr[i]/place) % base ] - 1 ] = arr[i];
		count[ (arr[i]/place) % base ]--; // reduce for the prev same guy
	}
	for (i=0; i<n; i++)
		arr[i] = op[i];
}

void radixSort(int * arr, int n, int base){
	int m = 0, i;
	for (i=0; i<n; i++) m = max(m, arr[i]);
	for (i=1; m/i > 0; i*=base){
		countSort(arr, n, i, base);
	}
}

int main(){
	int t, i;
	int arr[] = {22, 13, 40, 14, 88, 1, 57, 43};
	radixSort(arr, sizeof(arr)/sizeof(int), 16);

	for (i=0; i< (sizeof(arr)/sizeof(int)); i++)
		printf("%d ", arr[i]);

	return 0;
}