#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef set<int>::iterator siit;

int main(){
	int n, q;
	cin >> n >> q;
	set <int> s;
	int o, a, b, sign;
	siit it, it2;

	while (q--){
		scanf("%d %d %d", &o, &a, &b);
		if (o==0){
			if (s.find(a) != s.end()) s.erase(s.find(a));
			else s.insert(a);
			if (s.find(b) != s.end()) s.erase(s.find(b));
			else s.insert(b);
		} else {
			it = s.lower_bound(a);
			it2 = s.upper_bound(b);
			sign = distance(s.begin(), it) % 2;
			cout << sign << endl;
			for (; it != it2; ++it){ // lower bound

			}
		}
	}
	return 0;
}