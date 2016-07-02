#include "bits/stdc++.h"
#define MODULO 1000000000
#define endl '\n'
#define mdd(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/*
for m columns no of ways - 2m c m
	For m sum ways - 2m-1 c m
	For m-1 sum ways - 2m-2 c m-1
	For m-2 sum ways - 2m-3 c m-2
	......

Now to manage the rows.
	for n=1, ans1 = w0 + w1 + w2 ... wm
	for n=2, ans2 = wm * (ans1) + wm-1 * (ans1 - wm) .... 
*/

int main(){
	ios_base::sync_with_stdio(0);

	int t, i;
	int n,m,j;
	ull rowarrbs[2001], rowarr[2001], a, b, prev, prev2, bk, z;
	
	cin >> t;
	vector<ull> nums;
	vector<ull>::iterator numsi;

	while (t--){
		cin >> n >> m;

		nums.clear();
		a = m-1; b = 0; // for w0
		rowarrbs[0] = 1;
		rowarr[0] = 1;
		prev = 1;

		// fill last row
		for (i=1; i<=m; i++){
			a++; b=i;
			nums.push_back(a);

			for (numsi = nums.begin(); numsi != nums.end(); ++numsi){
				z = __gcd(*numsi, b);
				if (z > 1){
					if (z == (*numsi)){
						b /= z;
						//nums.erase(numsi);
						//numsi--;
						*numsi = 1;
					}
					else if (b == z){
						*numsi = (*numsi)/z;
						b = 1;
						break;
					} else {
						b /= z;
						*numsi = (*numsi)/z;
					}
				}
			}

			// calc
			prev2 = 1;
			for (numsi = nums.begin(); numsi != nums.end(); ++numsi) // dont optimize
				prev2 = mdd(prev2 * (*numsi));

			rowarrbs[i] = prev2;
			prev += rowarrbs[i];
			rowarr[i] = rowarrbs[i];
		}
		prev = mdd(prev);

		// calc for n
		for (i=2; i<=n; i++){
			prev2 = 0;
			for (j=m; j>=0; j--){
				bk = rowarr[j];
				rowarr[j] = mdd( rowarrbs[j] * prev );
				prev = mdd( ( prev + ((ull) MODULO) ) - bk );
				prev2 += rowarr[j];
			}
			prev = mdd(prev2);
		}

		// o/p the result
		cout << prev << endl;
	}

	return 0;
}