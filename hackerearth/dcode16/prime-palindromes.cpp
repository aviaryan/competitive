#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define LT 2000000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int IsPrime(unsigned long long n) {
	unsigned long long f, r;
    if (n < 2)
        return 0;
    else if (n < 4)
        return 1;
    else if (n % 2 == 0)
        return 0;
    else if (n < 9)
        return 1;
    else if (n % 3 == 0)
        return 0;
    else {
        r = floor(sqrt(n));
        f = 5;
        while (f <= r) {
            if (n % f == 0)
                return 0;
            if (n % (f + 2) == 0)
                return 0;
            f += 6;
        }
        return 1;
    }
}


ll reversen(ll n){
	ll s=0, r;
	while (n){
		r = n%10;
		s = s*10 + r;
		n = n/10;
	}
	return s;
}


int main(){
	int t, i, k;

	ios_base::sync_with_stdio(0);
	cin >> t;

	for (i=t; i<=LT; i++){
		if (IsPrime(i)){
			k = reversen(i);
			if (k == i){
				printf("%d\n", i);
				break;
			}
		}
	}


	return 0;
}