#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

#define si(a) scanf("%d", &a)
#define si2(a,b) si(a); si(b)

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n, u, l, r, val, q;
	//ios_base::sync_with_stdio(0);
	si(t);

	while (t--){
		si2(n,u);
		int arr[n+1];
		fill_n(arr, n+1, 0);
		for (i=0; i<u; i++){
			si(l); si(r); si(val);
			arr[l] += val;
			arr[r+1] -= val;
		}
		for (i=1; i<n; i++)
			arr[i] += arr[i-1];
		si(q);
		for (i=0; i<q; i++){
			si(val);
			printf("%d\n", arr[val]);
		}
	}

	return 0;
}