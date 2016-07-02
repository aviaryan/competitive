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

int n, m;
int b[100][100];

bool possible(int x, int y){
	if ((x >= 0) && (x<n) && (y >= 0) && (y < m) && b[x][y]==0)
		return true;
	else
		return false;
}


int main(){
	int t, i, x, k, j, ans, k1, k2;
	s(t);
	int r1[100][100], r2[100][100];

	while (t--){
		// get int
		scanf("%d %d %d %d", &n, &m, &k1, &k2);
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				s(b[i][j]);
				r1[i][j] = MODULO;
				r2[i][j] = MODULO;
			}
		}
		// k1
		r1[0][0] = 0;
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				// all possible jumps
				if (b[i][j] == 1) 
					continue;
				for (k=1; k<=k1; k++){
					// all possible places when k fixed
					for (x=0; x<=k; x++){
						if ( possible(i+x, j+(k-x)) )
							r1[i+x][j+(k-x)] = min(r1[i+x][j+(k-x)], r1[i][j]+1);
						if ( possible(i+x, j-(k-x)) )
							r1[i+x][j-(k-x)] = min(r1[i+x][j-(k-x)], r1[i][j]+1);
						if ( possible(i-x, j+(k-x)) )
							r1[i-x][j+(k-x)] = min(r1[i-x][j+(k-x)], r1[i][j]+1);
						if ( possible(i-x, j-(k-x)) )
							r1[i-x][j-(k-x)] = min(r1[i-x][j-(k-x)], r1[i][j]+1);
					}
				}
			}
		}
		// k1 reverse
		// r1[0][0] = 0;
		for (i=n-1; i>=0; i--){
			for (j=m-1; j>=0; j--){
				// all possible jumps
				if (b[i][j] == 1) 
					continue;
				for (k=1; k<=k1; k++){
					// all possible places when k fixed
					for (x=0; x<=k; x++){
						if ( possible(i+x, j+(k-x)) )
							r1[i+x][j+(k-x)] = min(r1[i+x][j+(k-x)], r1[i][j]+1);
						if ( possible(i+x, j-(k-x)) )
							r1[i+x][j-(k-x)] = min(r1[i+x][j-(k-x)], r1[i][j]+1);
						if ( possible(i-x, j+(k-x)) )
							r1[i-x][j+(k-x)] = min(r1[i-x][j+(k-x)], r1[i][j]+1);
						if ( possible(i-x, j-(k-x)) )
							r1[i-x][j-(k-x)] = min(r1[i-x][j-(k-x)], r1[i][j]+1);
					}
				}
			}
		}
		// k2
		r2[0][m-1] = 0;
		for (i=0; i<n; i++){
			for (j=m-1; j>=0; j--){
				// all possible jumps
				if (b[i][j] == 1) 
					continue;
				for (k=1; k<=k2; k++){
					// all possible places when k fixed
					for (x=0; x<=k; x++){
						if ( possible(i+x, j+(k-x)) )
							r2[i+x][j+(k-x)] = min(r2[i+x][j+(k-x)], r2[i][j]+1);
						if ( possible(i+x, j-(k-x)) )
							r2[i+x][j-(k-x)] = min(r2[i+x][j-(k-x)], r2[i][j]+1);
						if ( possible(i-x, j+(k-x)) )
							r2[i-x][j+(k-x)] = min(r2[i-x][j+(k-x)], r2[i][j]+1);
						if ( possible(i-x, j-(k-x)) )
							r2[i-x][j-(k-x)] = min(r2[i-x][j-(k-x)], r2[i][j]+1);
					}
				}
			}
		}
		// k2 reverse
		// r2[0][m-1] = 0;
		for (i=n-1; i>=0; i--){
			for (j=0; j<m; j++){
				// all possible jumps
				if (b[i][j] == 1) 
					continue;
				for (k=1; k<=k2; k++){
					// all possible places when k fixed
					for (x=0; x<=k; x++){
						if ( possible(i+x, j+(k-x)) )
							r2[i+x][j+(k-x)] = min(r2[i+x][j+(k-x)], r2[i][j]+1);
						if ( possible(i+x, j-(k-x)) )
							r2[i+x][j-(k-x)] = min(r2[i+x][j-(k-x)], r2[i][j]+1);
						if ( possible(i-x, j+(k-x)) )
							r2[i-x][j+(k-x)] = min(r2[i-x][j+(k-x)], r2[i][j]+1);
						if ( possible(i-x, j-(k-x)) )
							r2[i-x][j-(k-x)] = min(r2[i-x][j-(k-x)], r2[i][j]+1);
					}
				}
			}
		}

		// ans
		ans = MODULO;
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				if (b[i][j] == 1)
					continue;
				//printf("%d %d %d\n", i, j, max(r1[i][j], r2[i][j]));
				ans = min(ans, max(r1[i][j], r2[i][j]));
			}
		}
		if (ans == MODULO) ans = -1;
		p(ans);
	}

	return 0;
}