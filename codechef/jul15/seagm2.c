#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define ld double
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007
#define s(a) scanf("%d", &a)
#define sf(a) scanf("%lf", &a)


int main(){
	int t, i, j, n, m, forcezero, fzct, isSereja0;
	s(t);
	ld p, in, temp, none, ans, sereja;

	while (t--){
		s(n); s(m);
		p = 0.0;
		fzct = 0;
		isSereja0 = 0;

		for (i=0; i<n; i++){
			temp = 1.0;
			forcezero = 0;
			for (j=0; j<m; j++){
				sf(in);
				if (in == 0.0000)
					forcezero = 1;
				temp = temp * in;
			}
			if (forcezero){
				temp = 0.0;
				fzct++;
			}
			p = p + temp;
			if (i==0){
				sereja = temp;
				if (forcezero) isSereja0 = 1;
			}
		}

		none = 1.0 - p;

		if (fzct == n) // all 0
			ans = 0.0;
		else if (isSereja0 == 1)
			ans = 0.0;
		else if (fzct == n-1)
			ans = 1.0; // all others excluding sereja are 0
		// else if (none == 1.0) // the prev cause fzct == n is already tackled
		// 	ans = 1.0;
		else
			ans = sereja/p;

		if (ans >= 1.0) // possible by just a minor
			ans = 1.0;
		printf("%.6lf\n", ans);
	}

	return 0;
}

/*
1
4 4
0.0010 0.0010 0.0010 0.0010
0.9990 0.0000 0.0000 0.0000
0.0000 0.9990 0.0000 0.0000
0.0000 0.0000 0.9990 0.9990
*/