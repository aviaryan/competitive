#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ull> vull;

ull ans=0, s;
int n, n2;
vi arr;
vull arr2;

ull factorial(int s, ull lmt){
	ull ans=1;
	int i;
	for (i=2; i<=s; i++){
		ans = ans * i;
		if (ans>lmt){
			ans = 0;
			break;
		}
	}
	return ans;
}

void solve(ull csum, int j, int k){
	if (csum == s){
		ans++;
		return;
	} else if (csum > s){
		return;
	}
	//cout << csum;

	if (j<n)
		solve(csum + (ull)arr[j], j+1, k);
	if (k<n2)
		solve(csum + arr2[k], j, k+1);
}

int main(){
	int k, j, i;
	cin >> n >> k >> s;

	for (i=0; i<n; i++){
		cin >> j;
		arr.push_back(j);
		if (factorial(j, s) != 0)
			arr2.push_back(factorial(j,s));
	}

	sort(arr.begin(), arr.end());
	sort(arr2.begin(), arr2.end());
	n2 = arr2.size();
	solve(0, 0, 0);
	cout << ans;

	return 0;
}