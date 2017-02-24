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
int r1[100][100], r2[100][100];

bool possible(int x, int y, int num){
	if ((x >= 0) && (x<n) && (y >= 0) && (y < m) && b[x][y]==0){
		if (num==1)
			return (r1[x][y] == MODULO);
		else
			return (r2[x][y] == MODULO);
		// return true;
	}
	else
		return false;
}


int main(){
	int t, i, x, k, j, ans, k1, k2;
	s(t);
	queue< pair<int, int> > q;
	pair <int, int> p1;

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
		q.push(make_pair(0, 0));
		while (!q.empty()){
			p1 = q.front();
			q.pop();
			i = p1.first;
			j = p1.second;
			// all possible K (less thans)
			for (k=1; k<=k1; k++){
				// all possible places when k fixed
				for (x=0; x<=k; x++){
					if ( possible(i+x, j+(k-x), 1) ){
						r1[i+x][j+(k-x)] = r1[i][j]+1;
						q.push(make_pair(i+x, j+(k-x)));
					}
					if ( possible(i+x, j-(k-x), 1) ){
						r1[i+x][j-(k-x)] = r1[i][j]+1;
						q.push(make_pair(i+x, j-(k-x)));
					}
					if ( possible(i-x, j+(k-x), 1) ){
						r1[i-x][j+(k-x)] = r1[i][j]+1;
						q.push(make_pair(i-x, j+(k-x)));
					}
					if ( possible(i-x, j-(k-x), 1) ){
						r1[i-x][j-(k-x)] = r1[i][j]+1;
						q.push(make_pair(i-x, j-(k-x)));
					}
				}
			}
		}

		// k2
		r2[0][m-1] = 0;
		q.push(make_pair(0, m-1));
		while (!q.empty()){
			p1 = q.front();
			q.pop();
			i = p1.first;
			j = p1.second;
			// all possible K (less thans)
			for (k=1; k<=k2; k++){
				// all possible places when k fixed
				for (x=0; x<=k; x++){
					if ( possible(i+x, j+(k-x), 2) ){
						r2[i+x][j+(k-x)] = r2[i][j]+1;
						q.push(make_pair(i+x, j+(k-x)));
					}
					if ( possible(i+x, j-(k-x), 2) ){
						r2[i+x][j-(k-x)] = r2[i][j]+1;
						q.push(make_pair(i+x, j-(k-x)));
					}
					if ( possible(i-x, j+(k-x), 2) ){
						r2[i-x][j+(k-x)] = r2[i][j]+1;
						q.push(make_pair(i-x, j+(k-x)));
					}
					if ( possible(i-x, j-(k-x), 2) ){
						r2[i-x][j-(k-x)] = r2[i][j]+1;
						q.push(make_pair(i-x, j-(k-x)));
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