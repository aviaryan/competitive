#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef string::iterator sit;
string s;
char c;

void solve(string str, sit sbit){
	sit i = sbit;
	while (i != s.end()){
		cout << str << *i << endl;
		c = *i;
		solve(str + c, ++i);
	}
}

int main(){
	int t, n;
	cin >> t;

	while (t--){
		cin >> n >> s;
		sort(s.begin(), s.end());
		string z;
		solve(z, s.begin());
	}

	return 0;
}