#include "bits/stdc++.h"
#define MODULO 1000000007LL
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%lld\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

/*
5 - 
	[1 4] [2] [3 4] [5]

6 -
	[1 4 6] [2] [3 4] [5 6]

7 -
	[1 4 6] [2 7] [3 4] [5 6 7]

8 -
	[1 4 6] [2 7] [3 4] [5 6 7] [8]

9 - 
	.. 10, 11, 12, 

13 - 
	[1 4 6 xx] [2 7 xx] [3 4 xx] [5 6 7 xx] [8 xx] [13]
	.. 14, 15, 16, 17, 18, 19, 20


1 1 2 3 5 8 13 21 ...
*/

int main(){
	int times;
	ll i = 1, b = 1, t, c=0, n, ans;
	s(times);

	map <ll,ll> arr;
	arr[1] = 0;

	for (;i<MODULO*MODULO;){
		t = i;
		i = i + b;
		b = t;
		arr[i] = ++c;
	}


	while (times--){
		sl(n);
		ans = arr.lower_bound(n+1)->second;
		p(ans);
	}

	return 0;
}