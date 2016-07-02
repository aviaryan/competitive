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

int bc[10000+1], a[10000], b[10000];
int ans;
int n;

void solve(int pos, int target){
	if (pos == n){
		ans = max(target, ans);
		return;
	}
	int head = 0;
	if (bc[pos-1] != 0){ // gotta take it
		head += b[pos-1];
		bc[pos-1] = 0;
	}
	// solve
	if ( (a[pos] + head) == target ){
		solve(pos+1, target);
		return;
	}
	if (bc[pos] != 0)
		if ((a[pos] + head + bc[pos]) == target){
			bc[pos] = 0;
			solve(pos+1, target);
			return;
		}
	if (bc[pos] != 0 && bc[pos+1] != 0){
		if ((a[pos] + head + bc[pos] + bc[pos+1]) == target){
			bc[pos] = 0; bc[pos+1] = 0;
			solve(pos+1, target);
			return;
		}
	}
	if (bc[pos+1] != 0)
		if ((a[pos] + head + bc[pos+1]) == target){
			bc[pos+1] = 0;
			solve(pos+1, target);
			return;
		}
}

void copy_b(){
	int i;
	for (i=0; i<n; i++)
		bc[i] = b[i];
	bc[i] = 0;
}

int main(){
	int t, i;
	s(t);

	while (t--){
		s(n);
		for (i=0; i<n; i++) 
			s(b[i]);
		for (i=0; i<n; i++) 
			s(a[i]);
		// solve
		ans = -1;
		copy_b();
		solve(1, a[0]);
		copy_b(); bc[0] = 0;
		solve(1, a[0]+b[0]);
		if (n > 1){
			copy_b(); bc[0] = 0; bc[1] = 0;
			solve(1, a[0]+b[0]+b[1]);
			copy_b(); bc[1] = 0;
			solve(1, a[0]+b[1]);
		}
		// done
		p(ans);
	}

	return 0;
}