#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n;
	s(t);
	int arr[50000 * 2];

	while (t--){
		s(n);
		for (i=0; i<2*n; i++)
			s(arr[i]);
		sort(arr, arr+(2*n));
		p(arr[(n-1) + (n+1)/2]);
		for (i=0; i<n; i++) 
			printf("%d %d ", arr[i], arr[n+i]);
		printf("\n");
	}

	return 0;
}
