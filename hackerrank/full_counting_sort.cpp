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
	int t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> n;
	map <int, vector<string> > mp;
	string s;
	for (i=1; i<=n; i++){
		cin >> t >> s;
		if (i <= (n/2))
			s = "-";
		mp[t].push_back(s);
	}

	vector<string>::iterator it;
	for (i=0; i<100; i++){
		for (it = mp[i].begin(); it != mp[i].end(); it++)
			cout << *it << " ";
	}

	return 0;
}