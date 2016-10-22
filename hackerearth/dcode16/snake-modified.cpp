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
	ll t, i, n, x;
	s(t);

	while (t--){
		s(x);
		s(n);
		ll arr[n];
		for (i=0; i<n; i++){
			s(arr[i]);
		}
		sort(arr, arr+n);
		int steps = 0, del;
		int final = MODULO;
		// spl case
		if (x == 1 && arr[0] >= 1){
			printf("%d\n", n);
			continue;
		}
		for (i=0; i<n; i++){
			if (arr[i] >= x){
				del = (n-i);
				final = min(final, del + steps);

				x += (x-1);
				i = i-1;
				steps++;
			} else {
				x += arr[i];
				// p(x);
			}
		}
		final = min(steps, final);
		p(final);
	}

	return 0;
}