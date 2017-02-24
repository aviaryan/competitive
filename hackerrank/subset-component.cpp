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

/**
 * the deduction in connected components by each of the d[i] is disjoint
 * even when 5 and 9 have a common 1, their deduction can be classified distinctly
 */

// problem - 1101 and 1100 in same group
ull b[20];

void solve(ull i, ull cur){
	if (cur | b[i] == 0){
		
	}
	solve(i+1, cur | b[i]);
	solve(i+1, cur);
}

int num_of_ones(ull n){
	int c=0;
	while (n>0){
		if (n & 1 == 1) c++;
		n >>= 1;
	}
	return c;
}

int main(){
	int t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> n;
	ull no;
	ull total = 64 * pow(2, n);

	for (i=0; i<n; i++){
		cin >> b[i];
		no = num_of_ones(b[i]);
		cout << no << endl;
		if (no > 1){
			total = total - (pow(2, n-1) * (no-1));
		}
	}
	cout << total << endl;

	return 0;
}