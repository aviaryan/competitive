#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)

struct node {
	ll sum;
	ll mult;
	ll add;
};
typedef struct node nd;

nd tree[4*100000];
ll arr[100000+1];
int n, x, y, op;
ll v, sumans;

void buildtree(int l, int r, int p){
	tree[p].sum = m(arr[r]+MODULO-arr[l-1]);
	tree[p].add = 0;
	tree[p].mult = 1;

	if (l==r)
		return;
	int mid = (l+r)/2;
	buildtree(l, mid, p*2);
	buildtree(mid+1, r, p*2+1);
}

void pushUp(int p, ll diff){
// push ans up - all mult are cleared
	if (p == 0)
		return;
	tree[p].sum = m(tree[p].sum + diff);
	pushUp(p/2, diff);
}

void goDown(int p, int l, int r, ll mult, ll add){

	tree[p].sum = m( m(mult * tree[p].sum) + m(add * (ll) (r-l+1)) );
	add = m(mult * tree[p].add) + add; // use old mult
	mult = m(mult * tree[p].mult);

	if (x <= l && y >= r){ // boundary found no need to go down
		// use option then go up
		tree[p].mult = mult;
		tree[p].add = add;
		ll diff;
		if (op == 1){
			diff = m(v * (ll) (r-l+1));
			tree[p].sum = m(tree[p].sum + diff);
			tree[p].add = m(tree[p].add + v);
			pushUp(p/2, diff);
		} else if (op == 2){
			diff = m( (v-1) * tree[p].sum );
			tree[p].sum = m(tree[p].sum + diff);
			tree[p].mult = m(v * tree[p].mult);
			tree[p].add = m(v * tree[p].add);
			pushUp(p/2, diff);
		} else if (op == 3){
			diff = ( v * (ll) (r-l+1) - tree[p].sum );
			tree[p].sum = m(v * (ll) (r-l+1));
			tree[p].mult = 0;
			tree[p].add = v;
			pushUp(p/2, m(MODULO+diff)); // positivify
		} else {
			sumans = m( sumans + tree[p].sum );
		}
	} else if (l <= y && r >= x){
		int mid;
		tree[p].mult = 1;
		tree[p].add = 0;
		mid = (l+r)/2;
		if (l==r)
			return;
		goDown(2*p, l, mid, mult, add);
		goDown(2*p+1, mid+1, r, mult, add);
	} else {
		tree[p].mult = mult;
		tree[p].add = add;
	}

	return;
}

int main(){
	int t, i, q;
	//ios_base::sync_with_stdio(0);
	scanf("%d %d", &n, &q);

	arr[0] = 0;
	for (i=1; i<=n; i++){
		scanf("%lld", &arr[i]);
		arr[i] = m( arr[i] + arr[i-1] );
	}

	buildtree(1, n, 1);

	while (q--){

		scanf("%d", &op);
		if (op < 4){
			scanf("%d %d %lld", &x, &y, &v);
		} else {
			scanf("%d %d", &x, &y);
			sumans = 0;
		}
		goDown(1, 1, n, 1, 0);
		if (op == 4)
			printf("%lld\n", sumans);
	}


	return 0;
}
