// ported from ADDMUL

#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(z,a) scanf("%z", &a)
#define p(z,a) printf("%z\n", a)
#define si(a) scanf("%d", &a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll arr[100000*4+1];
ll exsums[100000*4+1];
int x, y, op;
ll v, sumans;

void goDown(int p, int l, int r, ll add){

	arr[p] = arr[p] + add * (ll) (r-l+1);
	add = exsums[p] + add; // use old add

	if (x <= l && y >= r){ // boundary found no need to go down
		// use option then go up
		exsums[p] = add;
		if (op == 0){
			arr[p] += v * (ll) (r-l+1);
			exsums[p] = exsums[p] + v;
		} else {
			sumans = sumans + arr[p];
		}
	} else if (l <= y && r >= x){
		int mid = (l+r)/2;
		exsums[p] = 0;

		if (v != 0){
			int sz=0;
			if (l <= x)
				sz = (x-l);
			if (r >= y)
				sz += (r-y);
			arr[p] += v * (ll) (r-l+1-sz);
		}

		if (l==r)
			return;
		goDown(2*p, l, mid, add);
		goDown(2*p+1, mid+1, r, add);
	} else {
		exsums[p] = add;
	}

	return;
}

int main(){
	int t, i, q, n;
	si(t);

	while (t--){
		si(n); si(q);
		fill_n(arr, 4*n+1, 0);
		fill_n(exsums, 4*n+1, 0);

		while (q--){
			si(op);
			if (op == 0){
				scanf("%d %d %d", &x, &y, &v);
			} else {
				scanf("%d %d", &x, &y);
				sumans = 0;
				v=0;
			}
			goDown(1, 1, n, 0);
			if (op == 1)
				printf("%lld\n", sumans);
		}
	}


	return 0;
}