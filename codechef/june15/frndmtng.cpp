#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/*
get the longest of tes.
then 4 zones. 0---rise--constant--decrease---0--0
clevel * cont / (te1 * te2)
*/

ll te1, te2, t1, t2;

ll vic_at_point(ll p){
	ll a=t2;
	if (p<t2) a=p; // at start
	if (p>te2) // p out of te2
		if ((p-te2) > t2) a=0; // totally out
		else a=t2-(p-te2); // some out

	if (a>te2)
		a = te2;

	// forward no t2
	if (p>=te2)
		return a;
	else if ((p+t1) > te2) // te2 ends abrupty
		a += te2-p;
	else a += t1; // enough te2
	return a;
}

int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll rise, cont, fall, zero;
	ll rlevel, clevel, dlevel;
	double ans;

	while (t--){
		cin >> te1 >> te2 >> t1 >> t2;
		if (te2 > te1){
			swap(te2, te1);
			swap(t2, t1);
		}
		// only 1 thng is sure te1 >= te2
		if (t2>=te2){
			rise=te2-t1;
			if (rise<0) rise=0;
		} else rise = t2;

		if ( (te2 + t2) > te1 ) zero = 0;
		else zero = te1 - (te2+t2);

		cont = te2;
		if (t2 > te2){
			cont = t2;
			if (cont >= te1) cont = te1;
			else if ((te1-cont) < t1) cont -= t1;
		} else if ((te1-cont) < t1) cont -= t1;
		cont -= rise;


		// fall is bcoz of 2 reasons
		fall = te1 - rise - cont - zero;

		// clevel = t2+t1; // by te2
		// rlevel = t1; // by te2
		// dlevel = 0;
		// if (fall != 0){
		// 	dlevel = (rise+cont+fall);
		// 	dlevel = dlevel - te2 + t2;
		// }
		rlevel = vic_at_point(0);
		clevel = vic_at_point(rise);
		dlevel = vic_at_point(rise+cont+fall);

		//cout << rise << cont << fall << zero << endl;
		ans = (((double) clevel + rlevel)/2.0) * (double) rise;
		ans += ( (double) clevel * cont );
		ans +=(((double) clevel + dlevel)/2.0) * (double) fall;
		ans = ans / ((double) te2);
		ans = ans / ((double) te1);
		cout << setprecision(10) << ans << endl;
	}
	return 0;
}