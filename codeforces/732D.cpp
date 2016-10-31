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

// WEAK TESTCASE
// NOT CORRECT CODE

int main(){
	int t, i, n, m;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	int arr[n];
	for (i=0; i<n; i++)
		cin >> arr[i];
	int days[m], x = m;
	for (i=0; i<m; i++){
		cin >> days[m];
		x += days[m];
	}
	bool attn[m+1];
	fill_n(attn, m+1, false);
	int attc = 0;
	for (i=0; i<n; i++){
		if (arr[i] && !attn[arr[i]]){
			attn[arr[i]] = true;
			attc++;
		}
		if (attc == m)
			break;
	}
	int z = i+1;
	for (i=x-1; i<n; i++){
		if (arr[i])
			break;
	}
	i = max(z, i+1);
	if (i > n){
		cout << -1;
	} else {
		cout << i;
	}
	return 0;
}