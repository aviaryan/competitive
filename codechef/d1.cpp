#include "bits/stdc++.h"
#define MODULO 10000
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll PowMod(int bs, int n){ // base^n % modULO
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

int main(){
	int t, i, j, n, srt, c, d, k, sc, ans[500001];
	ll a;
	ios_base::sync_with_stdio(0);
	cin >> t;

	ans[1] = 0;
	for (i=2; i<=500000; i++){
		k=i;
		sc = sqrt(i);
		c = 1; d = 0;
		while (k%2 == 0){
			k=k/2;
			d++;
		}
		c *= (d+1); d = 0;
		while (k%3 == 0){
			k=k/3;
			d++;
		}
		c *= (d+1);
		srt = sqrt(k);
		for (j=5; j<=srt; j+=2)
			if (k%j == 0){
				d = 0;
				do {
					k=k/j;
					d++;
				} while (k%j == 0);
				c *= (d+1);
				srt = sqrt(k);
				if (k==1) break;
			}

		if (k != 1) c *= (1+1);
		if (c > 1) c--;
		// c has total factors. now calc answer
		if (sc*sc == i) ans[i] = m(sc * PowMod(i, (c/2)-1));
		else ans[i] = PowMod(i, c/2);
	}

	//cout << "hi";

	while (t--){
		cin >> n;
		printf("%d\n", ans[n]);
	}

	return 0;
}