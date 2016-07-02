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
// mstep huh

int main(){
	int t, i, j, k, n;
	int arrx[50*50 + 1], arry[50*50 + 1], steps;

	s(n);
	for (i=0; i<n; i++)
		for (j=0; j<n; j++){
			scanf("%d", &k);
			arrx[k] = i;
			arry[k] = j;
		}

	n *= n;
	steps = 0;
	for (i=2; i<=n; i++)
		steps += abs( arrx[i] - arrx[i-1] ) + abs( arry[i] - arry[i-1] );

	t = steps*20;
	int hh = t/3600;
	t = t - hh*3600;
	int mm = t/60;
	t = t-mm*60;

	if (hh>100) hh%=100; // lose
	printf("%02d:%02d:%02d", hh, mm, t);

	return 0;
}