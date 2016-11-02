#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%lld", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	ll t, i, n;
	s(n);
	char str[n+1];
	scanf("%s", str);
	// pre-process
	ll dc = 0, uc = 0;
	ll darr[n], uarr[n];
	ll dsums[n+1]; dsums[0] = 0;
	for (i=0; i<n; i++){
		if (str[i] == 'D'){
			darr[dc] = i;
			dc++;
			dsums[i+1] = dsums[i] + i+1;
		} else {
			uarr[uc] = i;
			uc++;
			dsums[i+1] = dsums[i];
		}
	}
	// reverse sums
	ll usums[n+1]; usums[n] = 0;
	for (i=n-1; i>=0; i--){
		if (str[i] == 'U')
			usums[i] = (n-i) + usums[i+1];
		else
			usums[i] = usums[i+1];
	}
	// solve
	ll uct = 0, dct = 0, cycs, back, forw, ans;
	bool is_u;
	for (i=0; i<n; i++){
		is_u = (str[i] == 'U');
		if (!is_u) dct++;
		back = uct;
		forw = dc - dct;
		cycs = min(back, forw);
		ans = 0;
		// make ans
		// full cycles
		if (cycs > 0){
			ans = (dsums[darr[dct+cycs-1] + 1] - dsums[i+1] - (i+1) * cycs) * 2;
			ans += (usums[uarr[uct-cycs]] - usums[i] - (n-i) * cycs) * 2;
		}
		cycs++;  // as the cycles are now taken
		// edge case
		if (is_u){
			if (back >= forw){ // throw forward
				ans += n-1 - i + 1;
			} else {
				ans += (darr[dct+cycs-1] - i) + (darr[dct+cycs-1]+1);
			}
		} else {
			if (forw >= back){ // throw back
				ans += i + 1;
			} else {
				ans += (i - uarr[uct-cycs]) + (n-1 - uarr[uct-cycs] + 1);
			}
		}
		printf("%lld ", ans);
		// wrap up
		if (is_u) uct++;
	}
	return 0;
}