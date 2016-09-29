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


ll solve(ll n, ll k){
	if (n <= 0) 
		return -1;

	ll mid = n / k;
	if (k%2 != 0){
		if (mid * k < n) 
			mid++;
	} else {
		if ((mid * k) + (k/2) < n)
			mid++;
	}
	mid += (k/2);
	return mid;
}

int main(){
	int t, i;
	ll n, k, b, n2;
	ios_base::sync_with_stdio(0);
	vector <ll> v;
	s(t);

	while (t--){
		scanf("%lld %lld %lld", &n, &k, &b);
		v.clear();
		while (n > 0 && b > 0){
			n2 = solve(n, b);
			n -= n2;
			v.push_back(n2);
			b--;
			if (n2 < 0 || n2 > k){
				v.clear();
				break;
			}
		}
		if (b != 0)  // not exact taken
			v.clear();

		n2 = v.size();
		if (n2 == 0){
			printf("-1\n");
		} else {
			for (vector<ll>::iterator vi = v.begin(); vi != v.end(); vi++){
				n2--;
				if (n2 == 0)
					printf("%lld", *vi);
				else
					printf("%lld ", *vi);
			}
			printf("\n");
		}
	}

	return 0;
}