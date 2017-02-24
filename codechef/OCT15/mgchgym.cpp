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

bool subsetSum(int * arr, int sz, int sum){
	int i, j;
	sort(arr, arr+sz);
	bool dp[sum+1];
	memset(dp, false, sizeof(dp));
	dp[0] = 1;

	for (j=0; j<sz; j++){
		for (i=sum-arr[j]; i>=0; i--){
			if (dp[i])
				dp[i+arr[j]] = true;
		}
	}
	return dp[sum];
}

bool subsetSum_2k(int * arr, int sz, int sum){
	int i;
	int last = arr[0];
	for (i=1; i<sz; i++){
		if (arr[i] != last){
			break;
		}
	}
	int xyz[2];
	xyz[0] = last; xyz[1] = (i==sz) ? last : arr[i];
	return subsetSum(xyz, 2, sum);
}

int main(){
	int t, i, op, n, q, x, l, r, w;

	scanf("%d %d", &n, &q);

	int wt[n+1], cpy[n+1];

	for (i=1; i<=n; i++){
		scanf("%d", wt+i);
	}

	bool flag = false;
	if (n>10000) flag = true;

	while (q--){
		s(op);
		if (op == 1){
			scanf("%d %d", &i, &x);
			wt[i] = x;
		} else if (op == 2) {
			scanf("%d %d", &l, &r);
			x = (r+l)/2;
			for (i=l; i<=x; i++){
				swap(wt[i], wt[r-i+l]);
			}
		} else {
			scanf("%d %d %d", &l, &r, &w);
			for (i=l; i<=r; i++)
				cpy[i] = wt[i];
			if (flag ? subsetSum_2k(&cpy[l], r-l+1, w) : subsetSum(&cpy[l], r-l+1, w))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}

	return 0;
}

