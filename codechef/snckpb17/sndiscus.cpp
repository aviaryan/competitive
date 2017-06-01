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
	int t, i, n, j, k;
	s(t);
	int x1s[50], x2s[50], y1s[50], y2s[50];
	int cans, ans;

	while (t--){
		s(n);
		for (i=0; i<n; i++){
			scanf("%d %d %d %d", &x1s[i], &y1s[i], &x2s[i], &y2s[i]);
		}
		if (n == 1){
			printf("0\n"); continue;
		}
		ans = 100000;
		for (i=1; i<=50; i++){
			for (j=1; j<=50; j++){
				cans = -1;
				// check all snakes
				for (k=0; k<n; k++){
					if (x1s[k] == x2s[k]){ // vert
						if ( (y1s[k] <= j && y2s[k] >= j) || (y1s[k] >= j && y2s[k] <= j) ){ // sandwich
							cans = max(cans, abs(i - x1s[k]));
						} else { // slightly up or down
							cans = max(cans,
								min(abs(i - x1s[k]) + abs(j - y1s[k]), abs(i - x2s[k]) + abs(j - y2s[k]))
							);
						}
					} else { // horiz
						if ( (x1s[k] <= i && x2s[k] >= i) || (x1s[k] >= i && x2s[k] <= i) ){ // sandwich
							cans = max(cans, abs(j - y1s[k]));
						} else {
							cans = max(cans,
								min(abs(i - x1s[k]) + abs(j - y1s[k]), abs(i - x2s[k]) + abs(j - y2s[k]))
							);
						}
					}
					if (cans >= ans) break; // already not an answer case
				}
				// put in ans
				ans = min(ans, cans);
			}
		}
		p(ans);
	}

	return 0;
}