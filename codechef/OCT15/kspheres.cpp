#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define md(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i, n, m, c, j;
	scanf("%d %d %d", &n, &m, &c);
	ll nar[c+1], mar[c+1];

	fill_n(nar, c+1, 0);
	fill_n(mar, c+1, 0);

	for (i=0; i<n; i++){
		scanf("%d", &j);
		nar[j]++;
	}

	for (i=0; i<m; i++){
		scanf("%d", &j);
		mar[j]++;
	}

	ll car[c+1];
	for (i=1; i<=c; i++){
		car[i] = md(nar[i] * mar[i]);
	}

	ll csphs[c+1], spsum[c+1];
	spsum[0] = 0;
	for (i=1; i<=c; i++){
		csphs[i] = car[i];
		spsum[i] = md(spsum[i-1] + csphs[i]);
	}

	ll sum;
	for (i=1; i<=c; i++){
		//sum = 0;
		for (j=c; j>=1; j--){
			csphs[j] = md(spsum[j-1] * car[j]);
			//sum = md(sum + csphs[j]);
		}
		for (j=1; j<=c; j++)
			spsum[j] = md(spsum[j-1] + csphs[j]);
		printf("%lld ", spsum[c]);
	}

	return 0;
}