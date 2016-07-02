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
	string a,b,c,d,e,f;

	while (t--){
		cin >> a >> b >> c >> d >> e >> f;
		if ( (a==c && (a==e || a==f)) || (a==d && (a==e || a==f)) || (b==c && (b==e || b==f)) || (b==d && (b==e || b==f)) )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}