#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
#define d(a) printf(">>> %d\n", a)
#define dl(a) printf(">>> %lld\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define ALIMIT 100000

// cost v/s usability
vector < pair<int, int> > tickets[ALIMIT + 1];
vector <int> nodes[ALIMIT + 1];
ll tree[4*ALIMIT + 1];
ll mins[ALIMIT+1];
int n;


// set val in tree
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
		tree[p] = min(tree[2*p], tree[2*p+1]);
	}
}

// get val from tree
ll getAns(int l, int r, int x, int y, int p){
	int mid;
	if (l > y || r < x){ // out of boundary
		return 1e18;
	} else if (l <= x && r >= y){ // l..r oversizes the boundary
		return tree[p];
	} else {
		mid = (x+y)/2;
		return min(getAns(l, r, x, mid, p*2), getAns(l, r, mid+1, y, p*2+1));
	}
}


void solve_min_ticket(int item, int depth){
	if (item == 1) 
		return;
	vector < pair<int,int> >::iterator vit;
	ll mn = (ll) 1e18;
	int l, r, cost;
	// d(item);

	for (vit = tickets[item].begin(); vit != tickets[item].end(); vit++){
		cost = vit->first;
		l = max(0, depth - vit->second);
		r = depth-1;
		// d(l); d(r);
		mn = min(mn, getAns(l, r, 0, n-1, 1) + cost);
	}
	update_tree(mn, depth);
	mins[item] = mn;
}

// make answers
void solve(){
	int nd, depth;
	vector<int>::iterator vit;
	// visited
	bool visited[n+1];
	fill_n(visited, n+1, false);
	visited[1] = true;
	// stack for dfs (node, depth)
	stack < pair<int, int> > s;
	s.push(make_pair(1, 0));

	while (!s.empty()){
		nd = s.top().first;
		depth = s.top().second;
		s.pop();
		solve_min_ticket(nd, depth);

		for (vit = nodes[nd].begin(); vit != nodes[nd].end(); vit++){
			if (!visited[*vit]){
				visited[*vit] = true;
				s.push(make_pair(*vit, depth+1));
			}
		}
	}
}


int main(){
	int t, i, m, a, b, q, v, k, w;

	s(n); s(m);
	fill_n(tree, 4*ALIMIT, (ll) 1e18);
	update_tree(0, 0);
	fill_n(mins, ALIMIT+1, 0);

	for (i=1; i<n; i++){
		scanf("%d %d", &a, &b);
		nodes[b].push_back(a);
	}
	for (i=0; i<m; i++){
		scanf("%d %d %d", &v, &k, &w);
		tickets[v].push_back(make_pair(w, k));
	}
	solve();
	s(q);
	for (i=0; i<q; i++){
		s(a);
		printf("%lld\n", mins[a]);
	}

	return 0;
}