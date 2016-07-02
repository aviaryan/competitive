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
	ll pre;
	set<ll> arr;
	set<ll>::iterator sit;
	double ans;

	while (t--){
		cin >> te1 >> te2 >> t1 >> t2;
		if (te2 > te1){
			swap(te2, te1);
			swap(t2, t1);
		}
		
		ans = 0.0;
		arr.clear();
		arr.insert(0);
		if ( te1 > (te2+t2) )
			arr.insert(te2+t2);
		else
			arr.insert(te1);
		if (t2 > te2){
			if (te2 > t1)
				arr.insert( te2 - t1 );
			// else nothing
		} else {
			if (te2 > t1)
				arr.insert(t2);
		}
		if (t2 <= te2){
			if (te2 > t1)
				arr.insert(te2 - t1);
			else
				arr.insert(t2);
		} else {
			if (t2 < te1)
				arr.insert(t2);
		}

		sit = arr.begin();
		pre = *sit;
		sit++;
		for (; sit != arr.end(); ++sit){
			ans += ( ( (double) vic_at_point(pre) + vic_at_point(*sit) ) / 2.0 ) * ((double) *sit-pre);
			//cout << "x: " << pre << " " << *sit << endl;
			pre = *sit;
		}

		ans = ans / ((double) te2);
		ans = ans / ((double) te1);
		cout << setprecision(30) << ans << endl;
	}
	return 0;
}