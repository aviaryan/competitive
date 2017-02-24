#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d ", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/*
5 1 4 2 3
3 2 4 1 5
4 1 3 2
2 3 1 4
*/

int main(){
	int t, i, n;
	s(t);

	while (t--){
		s(n);
		if (n%2 != 0) p(n/2 + 1);
		for (i=n/2; i>=1; i--)
			printf("%d %d ", i, n-i+1);
		printf("\n");
	}

	return 0;
}