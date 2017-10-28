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
	vector<string> v;
	string s;
	int i;

	while (1) {
	    getline(cin, s);
	    if (!s.empty())
	    	v.push_back(s);
	    else
	    	break;
	}

	int l = v.size();
	int l2 = l/2;

	for (i=l2; i<l; i++){
		cout << v[i] << endl;
	}
	for (i=0; i<l2; i++){
		cout << v[i] << endl;
	}

	return 0;
}
