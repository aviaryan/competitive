#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

struct node {
	ll sum;
	ll mult;
	ll add;
};

struct node tree[100000 * 4]; // some research said that
ll arr[100000+1];
int x, y, op;
ll v, sumans;

void buildtree(int l, int r, int p){
	tree[p].sum = m(arr[r]+MODULO-arr[l-1]);
	tree[p].add = 0;
	tree[p].mult = 1;

	if (l>=r)
		return;
	int mid = (l+r)/2;
	buildtree(l, mid, p*2);
	buildtree(mid+1, r, (p*2)+1);
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
	int t, i, q, n;
	ios_base::sync_with_stdio(0);
	cin >> n >> q;

	arr[0] = 0;
	for (i=1; i<=n; i++){
		cin >> arr[i];
		arr[i] = m( arr[i] + arr[i-1] );
	}

	buildtree(1, n, 1);

	while (q--){
		cin >> op;
		if (op < 4){
			cin >> x >> y >> v;
		} else {
			cin >> x >> y;
			sumans = 0;
		}
		goDown(1, 1, n, 1, 0);
		if (op == 4)
			cout << sumans << endl;
	}


	return 0;
}

/*
4 4
1 2 3 4
4 1 4
1 1 3 10
2 2 4 2
4 1 4
*/