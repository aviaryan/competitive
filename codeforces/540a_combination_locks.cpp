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
	string s1, s2;
	int ans=0, z;

	cin >> s1 >> s2;
	for (int i=0; i<t; i++)
		ans += min( abs(s1[i]-s2[i]) , 10-abs(s1[i]-s2[i]) );
	cout << ans << endl;

	return 0;
}