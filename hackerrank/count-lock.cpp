#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int maxsofar, n, m;
char str[100][101];

void solve(int x, int y, int d, int k){ // u d l r
	if (d!=0)
		if possible(x-1, y) solve(x-1, y, )
}

bool possible(int x, int y){
	return x>=0 && y>=0 && x<n && y<m && str[x][y] == '.';
}

int main(){
	int t, k, x, y;
	cin >> t;

	while (t--){
		cin >> n >> m;
		x = -1;

		for (i=0; i<n; i++){
			scanf("%s", str[i]);
			if (x==-1)
			for (j=0; j<m; j++)
				if (str[i][j] == 'M'){
					x = i, y = j;
					break;
				}
		}
		cin >> k;

		maxsofar = 0;
		solve(x, y, p)
	}
	return 0;
}