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


double PowMod(double bs, ll n){ // base^n % modULO
    double ret = 1;
    double a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a;
        a = a * a;
        n >>= 1;
    }
    return ret;
}

double powTogether(double elem, ll t, ll s){
	ll ps = (s>0) ? 4*t - s : 4*t - s; // f*** sign
	return ps<0 ? (1.0 / PowMod(2.0, -ps)) : PowMod(2.0, ps);
}

double powTogetherInv(double elem, ll t, ll s){
	ll ps = (s>0) ? 4*t + s : 4*t + s; // f***
	return ps<0 ? (1.0 / PowMod(2.0, -ps)) : PowMod(2.0, ps);
}

int main(){
	int t;
	ll i, k, s;
	double ai, bi;
	scanf("%lld %lld %lld", &i, &k, &s);
	scanf("%lf %lf", &ai, &bi);

	double x = sqrt(2);
	double xy = x * sqrt(3);
	
	double a1 = x * (ai + bi) - xy * (ai - bi);
	double b1 = x * (ai - bi) + xy * (ai + bi);

	double a2 = x * (a1 + b1) - xy * (a1 - b1);
	double b2 = x * (a1 - b1) + xy * (a1 + b1);

	double aj1 = a1 / ai , aj2 = a2 / a1 , bj1 = b1 / bi , bj2 = b2 / b1;
	ll t1, t2;
	double akq, bkq;

	if (k <= i){
		t2 = ceil( (i-k) / 2.0 );
		t1 = (i-k) - t2;
		akq = ai / powTogetherInv(aj1 * aj2, t1, s);
		bkq = bi / powTogetherInv(bj1 * bj2, t1, s);
		if (t2 > t1){
			akq /= aj2; bkq /= bj2;
		}
	} else {
		t1 = ceil( (k-i) / 2.0 );
		t2 = (k-i) - t1;
		akq = ai * powTogether(aj1 * aj2, t2, s);
		bkq = bi * powTogether(bj1 * bj2, t2, s);
		if (t1 > t2){
			akq *= aj1; bkq *= bj1;
		}
	}

	printf("%.4lf", akq + bkq);

	return 0;
}