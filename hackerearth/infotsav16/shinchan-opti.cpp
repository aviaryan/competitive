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
	ll t, i, m, cost;
	// ios_base::sync_with_stdio(0);
	cin >> m;
	ll costs[m];

	for (i=0; i<m; i++){
		cin >> cost;
		costs[i] = cost;
	}

	string strs[m];
	for (i=0; i<m; i++){
		cin >> strs[i];
	}

	ll dp[m], rdp[m], cmp, rcmp;
	dp[m-1] = 0;
	rdp[m-1] = costs[m-1];
	for (i=m-2; i>=0; i--){
		// normal case
		cmp = strs[i].compare(strs[i+1]);
		string sp1rev = strs[i+1];
		reverse(sp1rev.begin(), sp1rev.end());
		rcmp = strs[i].compare(sp1rev);
		if (cmp <= 0){
			dp[i] = dp[i+1];
		} else {
			dp[i] = -1;
		}
		if (rcmp <= 0){
			if (dp[i] == -1)
				dp[i] = rdp[i+1];
			else
				dp[i] = min(dp[i], rdp[i+1]);
		} else {
			dp[i] = -1;
		}

		// reverse case
		string srev = strs[i];
		reverse(srev.begin(), srev.end());
		cmp = srev.compare(strs[i+1]);
		// cout << srev << strs[i+1] << srev.compare(strs[i+1]);
		rcmp = srev.compare(sp1rev);
		if (cmp <= 0 && dp[i+1] != -1){
			rdp[i] = costs[i] + dp[i+1];
		} else {
			rdp[i] = -1;
		}
		if (rcmp <= 0 && rdp[i+1] != -1){
			if (rdp[i] == -1)
				rdp[i] = costs[i] + rdp[i+1];
			else
				rdp[i] = min(rdp[i], costs[i] + rdp[i+1]);
		} else {
			rdp[i] = -1;
		}
	}

	ll ans;
	if (dp[0] == -1)
		ans = rdp[0];
	else if (rdp[0] == -1)
		ans = dp[0];
	else
		ans = min(rdp[0], dp[0]);
	cout << ans << endl;

	return 0;
}