#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

#define pair<int, int>> pii;

typedef unsigned long long ull;
typedef long long ll;

int k;
bool def[100][100];


int numberOfPaths(int m, int n){
    pii count[m][n];
    pii countv[m][n];

    // Count of paths to reach any cell in first column is 1
    for (int i = 0; i < m; i++){
    	count[i][0].second = 0;
        count[i][0].first = -1;
        countv[i][0].second = 0;
        countv[i][0].first = 
    }
 
    // Count of paths to reach any cell in first row is 1
    for (int j = 0; j < n; j++){
    	count[0][j].second = 0;
        count[0][j].first = 1;
    }
 
    // Calculate count of paths for other cells in bottom-up manner using
    // the recursive solution
    for (int i = 1; i < m; i++){
        for (int j = 1; j < n; j++){
            // By uncommenting the last part the code calculatest he total
            // possible paths if the diagonal Movements are allowed
            count[i][j] = count[i-1][j] + count[i][j-1]; //+ count[i-1][j-1];
        }
    }
    return count[m-1][n-1];
}


int main(){
	int t, i, j, n, m, di, dj;
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> k;
	cin >> d;

	// init
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			def[i][j] = false;
		}
	}

	// bad
	for (i=0; i<d; i++){
		cin >> di >> dj;
		def[di-1][dj-1] = true;
	}



	return 0;
}