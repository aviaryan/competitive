#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

#define si(a) scanf("%d", &a)
#define si2(a,b) scanf("%d %d", &a, &b);

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int t, i, n, u, l, r, val, q;

	si2(n,u);
	int arr[n+1];
	fill_n(arr, n+1, 0);
	for (i=0; i<u; i++){
		si2(l,r);
		arr[l-1] += 1;
		arr[r] -= 1;
	}
	for (i=1; i<n; i++)
		arr[i] += arr[i-1];
	sort(arr, arr+n);

	printf("%d\n", arr[n/2] );

	return 0;
}