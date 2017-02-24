#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/*
sort that
1 2 3 4
4 = 2^3-1
3 = 2^2-1
2 = 2^1-1
1 = 2^0-1

-s
4 = 0
3 = 1
2 = 3
1 = 7
*/

int main(){
	ll n, t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll ans, ps, ansneg, arr[100000];

	while (t--){
		cin >> n;
		for (i=0; i<n; i++) cin >> arr[i];
		//quicksort(n, arr);
		sort(arr, arr+n);
		ps = 0; ans=0;
		for (i=0; i<n; i++){
			ans = m(ans + m(ps*arr[i]));
			ps = m(ps*2+1);
		}
		ps = 0; ansneg = 0;
		for (i=n-1 ; i>=0; i--){
			ansneg = m(ansneg + m(ps*arr[i]));
			ps = m(ps*2+1);
		}
		ans += MODULO;
		cout << m(ans-ansneg) << endl;
	}
	return 0;
}