#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
 
// 2^17 = 131072
int arr[100000];
int tree[2*131072];
int c, l, r;
pair <int,int> dishes[100000]; // cost , dish(rating)
multiset <int> costarr[201];
ll ans;
ll sols[2840+1][501]; // 500/1 + 500/2 ... 500/200

void makeTree(int p, int cl, int cr){
	if (l <= cl && r >= cr){
		if (c < tree[p])
			tree[p] = c;
		return;
	}
	if (l >= cl && r <= cr)
		if (tree[p] <= c)
			return;
 
	if (cl == cr || cr < l || cl > r)
		return;
 
	int mid = (cl+cr)/2;
	makeTree(2*p, cl, mid);
	makeTree(2*p+1, mid+1, cr);
}
 
int minCost(int n2, int n, int k){
	int i, j, cost, ai=0;

	for (i=1; i<=200; i++) { costarr[i].clear(); }

	for (i = 0; i<n; i++){
		if (arr[i] >= 0)
			continue;
		cost = tree[i+n2];
		j = (i+n2)/2;
		while (j > 0){
			if (cost > tree[j])
				cost = tree[j];
			j /= 2;
		}
 
		if (cost <= k)
			costarr[cost].insert( - arr[i] );
	}

	multiset <int>::reverse_iterator rr;
	int lt;
	for (i=1; i<=200; i++){
		lt = k / i;
		for (rr = costarr[i].rbegin(); rr != costarr[i].rend(); ++rr){
			dishes[ai++] = make_pair(i, *rr);
			lt--;
			if (lt<1)
				break;
		}
	}
	return ai;
}
 
int make2pow(int n){ // make x : x = pow(2, y) && x >=n
	int p = ceil( log(n) / log(2) );
	return pow(2, p);
}

ll solve(int k, int sz){
	int i,j;

	for (i=0; i<=sz; i++){
		for (j = 0; j<=k; j++){
			if (i==0 || j==0)
				sols[i][j] = 0;
			else if ( dishes[i-1].first <= j )
				sols[i][j] = max( dishes[i-1].second + sols[i-1][ j-dishes[i-1].first ] , sols[i-1][j] );
			else
				sols[i][j] = sols[i-1][j];
		}
	}

	return sols[sz][k];
}
 
int main(){
	int t, i;
	//ios_base::sync_with_stdio(0);
	s(t);
	int n,k,m,n2,ms_n;
	ll sum;
 
	while (t--){
		sum = 0;
		scanf("%d %d %d", &n, &k, &m);
		for (i=0; i<n; i++){
			s(arr[i]);
			sum += arr[i];
		}
 
		n2 = make2pow(n);
		fill_n(tree, 2*n2, 500+1);
		for (i=0; i<m; i++){
			scanf("%d %d %d", &l, &r, &c);
			makeTree(1, 1, n2);
		}
 
		// parse tree and get min costs
		ms_n = minCost(n2,n,k);
		if (ms_n == 0){
			printf("%lld\n", sum);
			continue;
		}

		ans = solve(k, ms_n);
		printf("%lld\n", sum+ans);
	}
 
	return 0;
}