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

ll arr[1 << 14];
ll sums[1 << 14 + 1];

int solve(int l, int r, int score){
	ll sum = sums[r+1] - sums[l], csum = 0;
	ll hsum = sum / 2LL;
	if (sum % 2 == 1)
		return score;
	int i;
	for (i=l; i<=r; i++){
		csum += arr[i];
		if (csum == hsum)
			break;
	}
	if (i > r)
		return score;
	int z = max(solve(l, i, score + 1), solve(i+1, r, score + 1));
	return z;
}

int main(){
	int t, i, n;
	s(t);

	while (t--){
		s(n);
		// get input, preprocess sums
		sums[0] = 0;
		for (i=0; i<n; i++){
			sl(arr[i]);
			sums[i+1] = arr[i] + sums[i];
		}
		// solve (testcases are weak)
		if (sums[n] == 0)
			p(n-1);
		else
			p(solve(0, n-1, 0));
	}

	return 0;
}