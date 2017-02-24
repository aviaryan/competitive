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

bool ans;

void solve(ll r, ll c, ll a, ll b){
	if (r<=0 || c<=0)
		return;
	if (a%r == 0 && b%r == 0){
		if ((a/r + b/r) == c)
			ans = true;
	}
	if (a%c == 0 && b%c == 0){
		if ((a/c + b/c) == r)
			ans = true;
	}
}


int main(){
	int t, i;
	ll r, c, m, k, j;
	// ios_base::sync_with_stdio(0);
	s(t);

	while (t--){
		scanf("%lld %lld %lld %lld %lld", &r, &c, &m, &k, &j);
		if (m>k) swap(m,k);
		if (k>j) swap(k,j);
		if (m>k) swap(m,k);
		ans = false;

		if (j%c == 0){
			solve(r - j/c, c, m, k);
		}
		if (j%r == 0){
			solve(r, c - j/r, m, k);
		}

		if (k%c == 0){
			solve(r - k/c, c, m, j);
		}
		if (k%r == 0){
			solve(r, c - k/r, m, j);
		}

		if (m%c == 0){
			solve(r - m/c, c, j, k);
		}
		if (m%r == 0){
			solve(r, c - m/r, j, k);
		}

		if (ans){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}

	return 0;
}