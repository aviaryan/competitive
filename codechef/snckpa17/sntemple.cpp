#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%lld\n", a)
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
 
 
// RMQ
class SegmentTree {
	private:
		int tree[4 * 100000];
		int * arr;
 
	public:
		SegmentTree(int * array);
		void build(int l, int r, int p);
		int rminq(int l, int r, int x, int y, int p);
};

SegmentTree::SegmentTree(int * array){
	arr = array;
}
 
void SegmentTree::build(int l, int r, int p){
	if (l == r){
		tree[p] = arr[l];
	} else {
		int mid = (l+r)/2;
		build(l, mid, 2*p);
		build(mid+1, r, 2*p+1);
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
}
 
int SegmentTree::rminq(int l, int r, int x, int y, int p){
	int mid;
	if (l > y || r < x){ // out of boundary
		return MODULO;
	} else if (l <= x && r >= y){ // l..r oversizes the boundary
		return tree[p];
	} else {
		mid = (x+y)/2;
		return min(rminq(l, r, x, mid, p*2), rminq(l, r, mid+1, y, p*2+1));
	}
}
 
 
 
int main(){
	int t, i, n, lside, rside, lmin, rmin, finside;
	ll ans, cans;
	s(t);
	int hs[100000 + 1];
	ll sums[100000 + 1];
	int fneg[100000 + 1];
	int bneg[100000 + 1];
 
	while (t--){
		s(n);
		for (i=1; i<=n; i++){
			s(hs[i]);
		}
		sums[0] = 0;
		for (i=1; i<=n; i++){
			sums[i] = sums[i-1] + (ll) hs[i];
		}
		// create rmq
		for (i=1; i<=n; i++){
			fneg[i-1] = hs[i] - i;
		}
		for (i=n; i>0; i--){
			bneg[i-1] = hs[i] - (n - i + 1);
		}
		SegmentTree ft(fneg); ft.build(0, n-1, 1);
		SegmentTree bt(bneg); bt.build(0, n-1, 1);
		// solve
		ans = sums[n] - 1LL;
		for (i=1; i<=n; i++){
			// left side
			lside = min(i-1, hs[i] - 1);
			if (lside > 0){
				lmin = ft.rminq(i - 1 - lside, i-2, 0, n-1, 1) + (i - lside - 1);
				if (lmin < 0){ // 1 2 2 (4) ...
					lside = min(i-1, hs[i] + lmin - 1);
				}
			}
			if (lside <= 0){ // only a single tower
				continue;
			}
			// right side
			rside = min(n - i, hs[i] - 1);
			if (rside > 0){
				rmin = bt.rminq(i+1 - 1, i-1 + rside, 0, n-1, 1) + (n - i - rside);
				if (rmin < 0){
					rside = min(n - i, hs[i] + rmin - 1);
				}
			}
			finside = min(lside, rside);
			if (finside <= 0){ // only a single tower
				continue;
			}
			// calc ans
			cans = sums[i - finside - 1]; // left full cut
			cans += sums[n] - sums[i + finside]; // right full cut
			cans += (sums[i + finside] - sums[i - finside - 1]) - ((ll) (finside+1LL)) - ((ll) finside * ((ll) finside + 1LL)); 
			// printf("%lld %d\n", cans, i);
			// ^ triangle
			ans = min(ans, cans);
		}
		p(ans);
	}
 
	return 0;
}
