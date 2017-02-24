#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define s(a) scanf("%d", &a)
#define MODULO 1000000007
#define m(a) ((a)%MODULO)

int main(){
	int t, i, n, l, j, a, b;
	int board[100001];
	int ladders[100001];
	s(t);

	for (j=1; j<=t; j++){
		s(n);
		s(l);
		memset(ladders, 0, sizeof(int) * (n+1));

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