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

ll globScore;
ll arr[77777], sums[77777+1];

// TODO: check from the other side
// TODO: absolute usually have less, calc them first
void solve(int m, int l, int r, ll score){
	// getting heavy
	if (score >= globScore)
		return;
	// trivial case
	if (m % (r-l+1) == 0){
		if (score < globScore)
			globScore = score;
		return;
	}
	// last pillar case
	ll minScore = sums[r-1] - sums[l-1];
	solve(0, r, r, score + minScore);
	// other cases
	int i;
	ll cscore;
	for (i=r-2; i>=l; i--){
		if ((r-i) > m)  // m exhausted
			break;
		cscore = (sums[i] - sums[l-1]) * (ll) (r - i);
		// TODO: update minScore if cscore comes out less (eg absolute)
		if (cscore < minScore){
			if (m % (r-i) == 0){ // trivial case
				minScore = min(cscore, minScore);
				solve(0, i+1, r, score + cscore);
			} else
				solve(m - (r-i), i+1, r, score + cscore);
		}
	}
	// next level case
	if (m > (r-l+1))
		solve(m - (r-l+1), l, r, score);
}

int main(){
	int t, i, n, m;
	s(t);

	while (t--){
		scanf("%d %d", &n, &m);
		// get input
		sums[0] = 0;
		for (i=0; i<n; i++){
			scanf("%lld", &arr[i]);
		}
		// preparations
		sort(arr, arr+n);
		for (i=0; i<n; i++){
			sums[i+1] = arr[i] + sums[i];
		}
		// trivial case
		if (m % n == 0){
			printf("0\n");
			continue;
		}
		// real deal
		globScore = (ll) 1e18;
		solve(m, 1, n, 0);
		printf("%lld\n", globScore);
	}

	return 0;
}