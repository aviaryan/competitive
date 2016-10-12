#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// CUSTOM TYPES

typedef struct {
	int five;
	int two;
	int carry_five;
	int carry_two;
	bool flag;
} node;

typedef struct {
	int five;
	int two;
} num;

// DECLARATIONS

node tree[4 * 100000 + 1];
num xFactor;

// ACC FUNCTIONS

num calcFactors(int k){
	num s;
	s.five = 0; s.two = 0;
	while (k % 2 == 0){
		k /= 2;
		s.two++;
	}
	while (k % 5 == 0){
		k /= 5;
		s.five++;
	}
	return s;
}

node basicNode(num factors){
	node newNode;
	newNode.five = factors.five; newNode.two = factors.two;
	newNode.carry_five = 0; newNode.carry_two = 0;
	newNode.flag = false;
	return newNode;
}

// TREE FUNCTIONS

void buildTree(int l, int r, int p){
	if (l==r){
		tree[p] = basicNode(calcFactors(arr[l]));
		return;
	}
	int mid = (l+r)/2;
	buildTree(l, mid, p*2);
	buildTree(mid+1, r, p*2+1);
	tree[p] = tree[p*2]
	tree[p].five += tree[p*2+1].five;
	tree[p].two += tree[p*2+1].two;
}

void pushUpdates(int p, int five_incr, int two_incr){
	p = p/2;
	while (p != 0){
		tree[p].five += five_incr;
		tree[p].two += two_incr;
		p = p/2;
	}
}

void updateTreeX(int l, int r, int x, int y, int p){
	int mid;
	if (l > y || r < x){ // out of boundary
		return;
	} else if (l <= x && r >= y){ // l..r oversizes the boundary
		tree[p].carry_five += xFactor.five;
		tree[p].carry_two += xFactor.two;
		tree[p].five += xFactor.five * (y-x+1);
		tree[p].two += xFactor.two * (y-x+1);
		pushUpdates(p, xFactor.five * (y-x+1), xFactor.two * (y-x+1));
	} else {
		mid = (x+y)/2;
		updateTreeX(l, r, x, mid, p*2);
		updateTreeX(l, r, mid+1, y, p*2+1);
	}
}

void updateTreeY(int l, int r, int x, int y, int p){
	int mid;
	
}

// MAIN

int main(){
	int t, i, n, m;
	int arr[100000];
	s(t);

	while (t--){
		scanf("%d %d", &n, &m);
		for (i=0; i<n; i++)
			scanf("%d", &arr[i]);
		// build tree
		for (i=0; i<m; i++){

		}
	}

	return 0;
}