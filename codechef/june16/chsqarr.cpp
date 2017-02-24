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

int arr[1000][1000];
int sum[1000][1001];
int mx_grps[1000][1000];
int que[1000];
int ans;

void make_grps(int row, int k, int sz){
	int i;
	int front = 0;
	int back = 0;
	int *ar = arr[row];
	int *mxs = mx_grps[row];
	// start
	que[0] = 0;
	for (i=1; i<k; i++){ // first grp
		while ( (back>=front) && (ar[que[back]] <= ar[i]) )
			back--;
		que[++back] = i;
	}
	for (; i<sz; i++){ // all others
		mxs[i-k] = ar[que[front]];
		// n/a numbers
		while ( (front<=back) && (que[front] <= i-k) )
			front++;
		// small than current
		while ( (back>=front) && (ar[que[back]] <= ar[i]) )
			back--;
		que[++back] = i;
	}
	// last one
	mxs[i-k] = ar[que[front]];

	// for (i=0; i<=(sz-k); i++)
	// 	printf("%d ", mxs[i]);
	// printf("\n");
}

void solve(int col, int k, int sz, int col_size){
	int i;
	int front = 0;
	int back = 0;
	int (*ar)[1000] = mx_grps;
	// int *mxs = mx_grps[row];
	int csum = sum[0][col+col_size] - sum[0][col];
	// start
	que[0] = 0;
	for (i=1; i<k; i++){ // first grp
		while ( (back>=front) && (ar[que[back]][col] <= ar[i][col]) )
			back--;
		que[++back] = i;
		csum += (sum[i][col+col_size] - sum[i][col]);
	}
	for (; i<sz; i++){ // all others
		// mxs[i-k] = ar[que[front]];
		ans = min( (k*col_size*ar[que[front]][col]) - csum , ans );
		// n/a numbers
		while ( (front<=back) && (que[front] <= i-k) )
			front++;
		// small than current
		while ( (back>=front) && (ar[que[back]][col] <= ar[i][col]) )
			back--;
		que[++back] = i;
		// updt sum
		csum -= (sum[i-k][col+col_size] - sum[i-k][col]);
		csum += (sum[i][col+col_size] - sum[i][col]);
	}
	// last one
	ans = min( (k*col_size*ar[que[front]][col]) - csum , ans );
}

int main(){
	int t, i, a, b, n, m, q, k, j;
	scanf("%d %d", &n, &m);
	for (i=0; i<n; i++)
		sum[i][0] = 0;
	// pre sum
	for (i=0; i<n; i++)
		for (j=1; j<=m; j++){
			s(arr[i][j-1]);
			sum[i][j] += arr[i][j-1] + sum[i][j-1];
		}
	// get inputs
	s(q);
	while (q--){
		scanf("%d %d", &a, &b);
		for (i=0; i<n; i++){ // make horiz groups
			make_grps(i, b, m);
		}
		// vertical grps over them and solve
		ans = MODULO;
		for (i=0; i<=(m-b); i++){
			solve(i, a, n, b);
		}
		p(ans);
	}

	return 0;
}
