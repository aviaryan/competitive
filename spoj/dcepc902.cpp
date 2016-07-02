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
	int t, i, n, l, j, a, b;
	//ios_base::sync_with_stdio(0);
	int board[100001];
	int ladders[100001];
	s(t);

	for (j=1; j<=t; j++){
		s(n);
		s(l);
		fill_n(ladders, n+1, 0);

		for (i=0; i<l; i++){
			scanf("%d %d", &a, &b);
			ladders[a] = b;
		}

		board[n] = 1;
		board[0] = 0; // for no ladders
		for (i=n-1; i>=1; i--)
			board[i] = m( board[i+1] + board[ladders[i]] );
		printf("Case #%d: %d\n", j, board[1]);
	}
	

	return 0;
}