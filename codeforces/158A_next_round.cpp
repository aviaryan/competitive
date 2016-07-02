#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int n,k,j,i,ans=0;
	int s=1;
	cin >> n >> k;

	for (i=0; i<n; i++){
		cin >> j;
		if (i==(k-1) && j!=0)
			s = j;
		if (s<=j)
			ans++;
	}

	cout << ans;
	return 0;
}