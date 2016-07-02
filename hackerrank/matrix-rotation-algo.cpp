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
	int t, i, n, m, r;
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> r;

	int arr[n][m];

	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			scanf("%d", &arr[i][j]);
		}
	}

	int cpy[n][m], szs[min(n,m)/2];

	int nb = n, mb = m, i=0;
	while (nb * mb > 0){
		szs[i] = nb * mb;
		i++;
		nb -= 2;
		mb -= 2;
	}

	

	return 0;
}