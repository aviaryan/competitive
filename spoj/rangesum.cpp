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
	int t, i, x, q;
	si(t);
	ll arr[t+1]; arr[0] = 0;
	scanf("%lld", arr+1);

	for (i=2; i<=t; i++){
		scanf("%lld", arr+i);
		arr[i] += arr[i-1];
	}

	int op, l, r, exptr=0;
	si(q);
	ll exarr[q+1], sum; 
	exarr[0] = 0;

	for (i=0; i<q; i++){
		si(op);
		if (op == 1){
			si2(l,r);
			if (l <= exptr){
				sum = exarr[ exptr - (l-1)] - exarr[ exptr - min(exptr,r) ]; // invert that arr
				if (r > exptr)
					sum += arr[r - exptr];
			} else {
				sum = arr[r - exptr] - arr[l-1-exptr];
			}
			printf("%lld\n", sum);
		} else {
			si(x);
			exarr[++exptr] = x + exarr[exptr-1];
		}
	}


	return 0;
}