#include "bits/stdc++.h"
#include <regex>
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t;
	cin >> t;
	string s;
	regex e("i)[a-z]");
	while (t--){
		cin >> s;
		if (regex_match(s, e))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}