#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t;
	cin >> t;
	string s;
	while (t--){
		cin >> s;
		if (s.size() < 11)
			cout << s << endl;
		else {
			cout << s[0] << s.size() - 2 << s[s.size()-1] << endl;
		}
	}
	return 0;
}