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


class SegmentTree {
	private:
		int tree[8 * 100000];
		int * arr;

	public:
		SegmentTree(int * array);
		void build(int l, int r, int p);
		int rmaxq(int l, int r, int x, int y, int p);
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
		tree[p] = max(tree[2*p], tree[2*p+1]);
	}
}

int SegmentTree::rmaxq(int l, int r, int x, int y, int p){
	int mid;
	if (l > y || r < x){ // out of boundary
		return -1;
	} else if (l <= x && r >= y){ // l..r oversizes the boundary
		return tree[p];
	} else {
		mid = (x+y)/2;
		return max(rmaxq(l, r, x, mid, p*2), rmaxq(l, r, mid+1, y, p*2+1));
	}
}



int main(){
	int t, i, n, k, p;
	ios_base::sync_with_stdio(0);
	cin >> n >> k >> p;
	int arr[2*n];

	for (i=0; i<n; i++){
		cin >> arr[i];
		arr[i+n] = arr[i];
	}

	if (k > n) 
		k = n;

	int carr[2*n]; carr[0] = arr[0];
	for (i=1; i<k; i++){
		arr[i] = arr[i-1] + arr[i]; // 1 0 1 0 becomes 1 1 2 2
		carr[i] = arr[i];
	}
	for (i=k; i<2*n; i++){
		carr[i] = arr[i] + carr[i-1];
		arr[i] = arr[i] + (carr[i-1] - carr[i-1-(k-1)]);
	}

	// for (i=0; i<2*n; i++){
	// 	printf("%d \n", arr[i]);
	// }

	SegmentTree myt(arr);
	myt.build(0, 2*n-1, 1);

	char str[p+1];
	int shift = 0, ans, tl, tr;
	cin >> str;
	for (i=0; i<p; i++){
		if (str[i] == '!'){
			shift = (shift + 1) % n;
		} else {
			ans = myt.rmaxq(0, n-1 - shift, 0, 2*n-1, 1); // ok
			ans = max(ans, myt.rmaxq(n-1 - (shift-1) + k-1, n-1 + (n-1 - (shift-1)), 0, 2*n-1, 1)); // looks correct per tests
			cout << ans << endl;
		}
	}

	return 0;
}