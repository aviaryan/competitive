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

int anss[500][500];
int n, m;

int getVal(int x, int y){
	if (x >= 0 && x < n && y >= 0 && y < m)
		return anss[x][y]+1; // return 1 if good is neighbour
	else
		return 1002;
}

int main(){
	int t, i, j, k, mx, mxc, ans, tans, ptans, temp;
	int a, b;
	s(t);
	int arr[500][500];
	int mxx[250000];
	int mxy[250000];

	while (t--){
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				s(arr[i][j]);
			}
		}
		mx = -1;
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				mx = max(mx, arr[i][j]);
			}
		}
		// find max points
		mxc = 0;
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				if (arr[i][j] == mx){
					mxx[mxc++] = i;
					mxy[mxc-1] = j;
				}
			}
		}
		// store cell answers
		for (i=0; i<n; i++){
			for (j=0; j<m; j++)
				anss[i][j] = 0;
		}
		// find max away point
		ans = 0;
		for (i=0; i<n; i++){
			for (j=0; j<m; j++){
				if (arr[i][j] != mx){
					// check neighbour and estimate
					temp = min(getVal(i-1, j), getVal(i-1, j-1));
					temp = min(temp, getVal(i, j-1));
					temp = min(temp, getVal(i-1, j+1));
					if (temp <= ans){
						anss[i][j] = temp; continue;
					}
					// find
					ptans = ans;
					for (k=0; k<mxc; k++){
						tans = max(abs(mxx[k] - i), abs(mxy[k] - j));
						if (tans <= ans) break; // no need, already less than ans
						if (ptans == ans)
							ptans = tans;
						else
							ptans = min(ptans, tans);
					}
					if (k == mxc){
						ans = ptans;
						anss[i][j] = ans;
					} else {
						anss[i][j] = tans;
					}
				}
			}
		}
		p(ans);
	}
	return 0;
}
