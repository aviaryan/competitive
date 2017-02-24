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

// http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/

int strict_upper_bound(int * lis, int len, int val){
	int l=-1, r=len-1, mid;
	while (r-l > 1){
		mid = l + (r-l)/2;
		if (lis[mid] >= val)
			r = mid;
		else
			l = mid;
	}
	return r;
}

int main(){
	int t, i, n, pos;
	ios_base::sync_with_stdio(0);
	cin >> n;
	int arr[n];
	for (i=0; i<n; i++)
		cin >> arr[i];
	int lis[n], len=1;
	lis[0] = arr[0];
	for (i=1; i<n; i++){
		if (arr[i] < lis[0])
			lis[0] = arr[i];
		else if (arr[i] > lis[len-1])
			lis[len++] = arr[i];
		else
			lis[strict_upper_bound(lis, len, arr[i])] = arr[i];
	}
	cout << len << endl;

	return 0;
}