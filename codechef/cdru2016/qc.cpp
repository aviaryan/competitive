#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define ALIMIT 40000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int factors[ALIMIT + 1];
ll answers[ALIMIT+1];

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


// primes
// build the prime table
void sieve(){
	int i, j;
	factors[1] = 1;
	fill_n(factors, ALIMIT+1, 1);
	for (i=2; i<=ALIMIT; i++){
		if (factors[i] != 1) continue;
		for (j=i; j<=ALIMIT; j+=i){
			if (factors[j] == 1)
				factors[j] = i;
		}
	}
}



int main(){
	ll t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll ans;
	// prev
	sieve();
	answers[1] = 0; answers[2] = 1; answers[3] = 3;
	ll powf = 2;
	for (i=4; i<=ALIMIT; i++){
		if (factors[i] == i)
			powf = m(powf * 2LL);
		answers[i] = m(answers[i-1] + powf);
	}

	while (t--){
		cin >> n;
		cout << answers[n] << endl;
	}
	return 0;
}