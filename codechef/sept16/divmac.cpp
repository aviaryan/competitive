#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define d(a) printf(">>> %d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// ---------

void update_tree(int v, int ind);

#define ALIMIT 1000000

int tree[4 * 100000 + 1];

int factors[ALIMIT + 1];
int arr[100000], n;

set <int> inds;
set <int>::iterator sit;

// builds the tree for getting max
void buildTree(int l, int r, int p){
	if (l==r){
		tree[p] = factors[arr[l]];
		return;
	}
	int mid = (l+r)/2;
	buildTree(l, mid, p*2);
	buildTree(mid+1, r, p*2+1);
	tree[p] = max(tree[p*2], tree[p*2+1]);
}

// build the prime table
void sieve(){
	int i, j;
	factors[1] = 1;
	fill_n(factors, ALIMIT+1, 1);
	for (i=2; i<=ALIMIT; i++){
		if (factors[i] != 1) continue;
		for (j=i; j<=ALIMIT; j+=i){
			if (factors[j] == 1)
				factors[j] = i;
		}
	}
}

// do the division operation
void update(int l, int r){
	int i;
	sit = inds.lower_bound(l);
	for (; sit != inds.end(); ){
		if (*sit > r) break;
		arr[*sit] /= factors[ arr[*sit] ];
		update_tree(factors[arr[*sit]], *sit);
		if (arr[*sit] == 1){
			inds.erase(sit++); // BUG chance
			// http://stackoverflow.com/questions/2874441/deleting-elements-from-stl-set-while-iterating
		} else {
			++sit;
		}
	}
}

void update_tree(int v, int ind){
	int mid, l=0, r=n-1, p=1;
	// find point
	while (l != r){
		mid = (l+r)/2;
		if (ind <= mid){
			p = p*2;
			r = mid;
		} else {
			p = p*2+1;
			l = mid+1;
		}
	}
	// move up
	tree[p] = v;
	while (p > 1){
		p = p/2;
		tree[p] = max(tree[2*p], tree[2*p+1]);
	}
}

// get ans 1...5
int getAns(int l, int r, int x, int y, int p){
	int mid;
	if (l > y || r < x){ // out of boundary
		return 1;
	} else if (l <= x && r >= y){ // l..r oversizes the boundary
		return tree[p];
	} else {
		mid = (x+y)/2;
		return max(getAns(l, r, x, mid, p*2), getAns(l, r, mid+1, y, p*2+1));
	}
}


// MAIN
int main(){
	int t, i, m, j, op, p1, p2;
	s(t);
	sieve();

	while (t--){
		scanf("%d %d", &n, &m);
		inds.clear();
		for (i=0; i<n; i++){
			s(arr[i]);
			inds.insert(i);
		}
		buildTree(0, n-1, 1);
		for (i=0; i<m; i++){
			scanf("%d %d %d", &op, &p1, &p2);
			if (op == 0){
				update(p1-1, p2-1);
			} else {
				//d(1);
				printf("%d ", getAns(p1-1, p2-1, 0, n-1, 1));
				//d(2);
			}
		}
		printf("\n");
	}

	return 0;
}
