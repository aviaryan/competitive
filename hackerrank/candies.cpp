#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007

typedef unsigned long long ull;
typedef long long ll;

int main(){
	int t, c, i;
	ios_base::sync_with_stdio(0);
	cin >> t;

	ll ans=0;
	int arr[t+2], cs[t+2];
	arr[0] =   999999;
	arr[t+1] = 999999;

	for (i=1; i<=t; i++)
		cin >> arr[i];
	
	int f=1;
	for (i=1; i<=t; i++){
		if (arr[i] > arr[i-1])
			f++;
		else
			f = 1;
		cs[i] = f;
	}

	f=1;
	for (i=t; i>=1; i--){
		if (arr[i] > arr[i+1])
			f++;
		else
			f=1;
		ans += ( cs[i] = max( f, cs[i] ) );
	}

	cout << ans;

	return 0;
}