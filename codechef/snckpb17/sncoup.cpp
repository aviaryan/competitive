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
	int t, i, n, ans;
	s(t);
	char s1[100000 + 1], s2[100000 + 1];
	int onep, secp, orig_onep;
	bool horiz;

	while (t--){
		s(n);
		scanf("%s", s1);
		scanf("%s", s2);
		assert(strlen(s1) == strlen(s2));
		vector<int> sn1, sn2;

		for (i=0; i<n; i++){
			if (s1[i] == '*') sn1.push_back(i);
			if (s2[i] == '*') sn2.push_back(i);
		}
		// simple cases
		if (sn1.size() == 0){
			printf("%d\n", max(0, (int) sn2.size() - 1)); continue;
		} else if (sn2.size() == 0) {
			printf("%d\n", max(0, (int) sn1.size() - 1)); continue;
		}
		// real case
		onep = 0; secp = 0; ans = 0;
		while(true){
			if (onep+1 < sn1.size() && secp+1 < sn2.size()){ // both have one ahead
				ans++;
				orig_onep = onep;
				if (sn1[onep] < sn2[secp+1]) onep++; 
				if (sn2[secp] < sn1[orig_onep+1]) secp++;
			} else if (onep+1 == sn1.size()){
				ans += (sn2.size()-1 - secp);
				break;
			} else {
				ans += (sn1.size()-1 - onep);
				break;
			}
		}
		p(ans + 1);
	}

	return 0;
}