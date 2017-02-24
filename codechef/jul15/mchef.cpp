#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

// 2^17 = 131072
int arr[100000];
int tree[2*131072];
ll dish_order[100000];
int c, l, r;
pair <int,int> dishes[100000]; // cost , dish(rating)
ll ans; int finish=0;

void quicksort(int ar_size, ll *  ar, pair<int,int> * pts) {
  pair<int, int> p_temp, p_prevmax, p_piv; //xxxxxxxx
  int piv;
  piv = ar[ar_size-1];
  p_piv = pts[ar_size-1];
  ll i, temp, c=0;
  ll prevmax, prevind=-1; //a/c ques

  for (i=0; i<ar_size-1; i++){
    if (ar[i] < piv){
      if ((prevind>-1) && (ar[i] < prevmax)){
        temp = ar[i];
        p_temp = pts[i]; //xxxxxxxxx
        ar[i] = prevmax;
        pts[i] = p_prevmax; //xxxxxxxxx
        ar[ prevind ] = temp;
        pts[ prevind ] = p_temp; //xxxxxxxx
        prevind = prevind+1;
        prevmax = ar[prevind];
        p_prevmax = pts[prevind]; //xxxxxxxxx
      }
      c++;
    }
    else if (prevind<0) {
      prevmax = ar[i];
      p_prevmax = pts[i]; //xxxxxxxxxx
      prevind = i;
    }
  }

  if (prevind>-1){
    ar[ar_size-1] = ar[c];
    pts[ar_size-1] = pts[c]; //xxxxxxxxxxx
    ar[c] = piv;
    pts[c] = p_piv; //xxxxxxxxxxxx
  }

  if (ar_size>2){
    if (c!=0)
      quicksort(c, &ar[0], &pts[0]);
    if (ar_size-c-1 != 0)
      quicksort(ar_size-c-1, &ar[c+1], &pts[c+1]);
  }
}


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

		if (cost <= k){
			dish_order[ai++] = ( (-arr[i] / (double) cost) * 100000 + cost );
			dishes[ai-1] = make_pair(cost, -arr[i]);
			//cout << i << " : " << cost << endl;
		}
	}
	quicksort(ai, dish_order, dishes);
	return ai;
}

int make2pow(int n){ // make x : x = pow(2, y) && x >=n
	int p = ceil( log(n) / log(2) );
	return pow(2, p);
}

void solve(int k_left, ll added, int sz){
	if (finish)
		return;
	if (k_left == 0){
		if (added > ans) ans = added;
		finish = 1;
		return;
	}

	//cout << p << endl;
	int p = dishes[sz].second, i;
	int tc = dishes[sz].first;

	if (tc > k_left){
		if (added > ans) ans = added;
		return;
	}
	if (sz == 0){
		if (added+p > ans) ans = added;
		return;
	}

	for (i=0; i<sz; i++)
		solve(k_left-tc, added+p, sz-1);
	solve(k_left, added, sz-1);
	return;
}

int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int n,k,m,n2,ms_n;
	ll sum;

	while (t--){
		sum = 0;
		cin >> n >> k >> m;
		for (i=0; i<n; i++){
			cin >> arr[i];
			sum += arr[i];
		}

		n2 = make2pow(n);
		fill_n(tree, 2*n2, 500+1);
		for (i=0; i<m; i++){
			cin >> l >> r >> c;
			makeTree(1, 1, n2);
		}

		// parse tree and get min costs
		ms_n = minCost(n2,n,k);
		if (ms_n == 0){
			cout << sum << endl;
			continue;
		}
		// brute force answer
		ans = 0; finish=0;
		solve(k , 0 , ms_n-1);
		cout << sum+ans << endl;
	}

	return 0;
}

/*
1
5 10 5
10 -2 -5 7 -10
1 1 5
2 4 10
4 4 12
3 4 10
1 5 15
*/