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

// ---------

#define ALIMIT 1000000

struct node {
	int lmax;
	int rmax;
};
typedef struct node nd;
nd tree[4 * 100000 + 1];

int factors[ALIMIT + 1];
int arr[100000], n;

set <int> inds;
set <int>::iterator sit;
map <int, int> segs;
map <int, int>::iterator mit;


void update_r(int l, int r, int x, int y, int p, int mx);



// builds the tree for getting max
void buildTree(int l, int r, int p, bool is_seg){
	if (l==r){
		tree[p].lmax = arr[l];
		tree[p].rmax = arr[l];
		return;
	}
	if (!is_seg && ((r-l) < 190)){ // z
		segs.insert(make_pair(l, r));
		is_seg = true;
	}
	int mid = (l+r)/2;
	buildTree(l, mid, p*2, is_seg);
	buildTree(mid+1, r, p*2+1, is_seg);
	tree[p].lmax = max(tree[p*2].lmax, tree[p*2].rmax);
	tree[p].rmax = max(tree[p*2+1].lmax, tree[p*2+1].rmax);
}

// build the prime table
void sieve(){
	int i, j;
	factors[1] = 1;
	fill_n(factors, ALIMIT, 1);
	for (i=2; i<=ALIMIT; i++){
		if (factors[i] != 1) continue;
		for (j=i; j<=ALIMIT; j+=i)
			factors[j] = i;
	}
}

// do the division operation
void update(int l, int r){
	int i, lmx;
	sit = inds.lower_bound(l);
	mit = segs.lower_bound(l);
	// get segments
	if (mit->first > l)
		mit--;
	for (; sit != inds.end(); sit++){
		lmx = 1;
		for (; sit != inds.end(); sit++){
			if (*sit > r)
				break;
			if (*sit > mit->second){
				update_r(l, r, mit->first, mit->second, lmx);
				break;
			}
			arr[i] /= factors[ arr[i] ];
			lmx = max(factors[arr[i]], lmx);
			if (arr[i] == 1) 
				inds.erase(sit); // BUG chance
		}
		mit++;
		if (sit == inds.end())
			update_r(l, r, mit->first, mit->second, lmx);
	}
}

void pushUp(int p, int mx, bool side){
	if (p == 0)
		return;
	if (side)
		tree[p].lmax = mx;
	else
		tree[p].rmax = mx;
	pushUp(p/2, mx, (p%2 == 0));
}

void update_r(int l, int r, int x, int y, int p, int mx){
	if (l > y || r < x){ // out of boundary
		return;
	} else if (l <= x && r >= y){ // l..r oversizes the boundary
		if (p % 2 == 1){
			pushUp(p/2, mx, false);
		} else {
			pushUp(p/2, mx, true);
		}
	} else { // can get more in
		mid = (l+r)/2;
		update_r(l, r, x, mid, p*2); 
		update_r(l, r, mid+1, y, p*2+1);
	}
}

// get ans
int getAns(int l, int r, int x, int y, int p){
	int mid, i;
	if (l > y || r < x){ // out of boundary
		return 1;
	} else if (l <= x && r >= y){ // l..r oversizes the boundary
		if ((y-x) < 200){ // z
			int mx = 1;
			for (i=x; i<=y; i++) 
				mx = max(mx, arr[i]);
			return mx;
		} else {
			return max(tree[p].lmax, tree[p].rmax);
		}
	} else { // can get more in
		mid = (l+r)/2;
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
		segs.clear();
		for (i=0; i<n; i++){
			s(arr[i]);
			inds.insert(i);
		}
		buildTree(0, n-1, 1, false);
		for (i=0; i<m; i++){
			scanf("%d %d %d", &op, &p1, &p2);
			if (op == 0){

			}
		}
	}

	return 0;
}
