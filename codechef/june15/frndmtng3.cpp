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
	ll arr[10];
	double ans;

	while (t--){
		cin >> te1 >> te2 >> t1 >> t2;
		if (te2 > te1){
			swap(te2, te1);
			swap(t2, t1);
		}
		
		if (t1+t2 == 0){
			cout << 0 << endl;
			continue;
		}

		ans = 0.0;

		for (i=0; i<te1; i++){
			ans += ( (double) vic_at_point(i) + vic_at_point(i+1) ) / 2.0;
			cout << i << ": " << vic_at_point(i) << vic_at_point(i+1) << endl;
		}

		ans = ans / ((double) te2);
		ans = ans / ((double) te1);
		cout << setprecision(30) << ans << endl;
	}
	return 0;
}