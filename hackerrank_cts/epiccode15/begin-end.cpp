#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	char str[t+1];
	cin >> str;
	ll rec[150] = {0};
	ll ans=0;

	for (i=0; i<t; i++){
		rec[ str[i] ]++;
		ans++;
	}

	for (i=97; i<123; i++)
		ans += (rec[i] * (rec[i]-1))/2; // x c 2
	
	cout << ans;

	return 0;
}