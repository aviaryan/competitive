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
	//ios_base::sync_with_stdio(0);
	s(t);

	// preprocess
	double probs[1001];
	probs[0] = 0.0;

	for (i=1; i<=1000; i++)
		probs[i] = probs[i-1] + (1.0 / (double) i);
	

	while (t--){
		s(n);
		printf("%.2lf\n", (double) n * probs[n]);
	}

	return 0;
}