#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%s", a)
#define d(a) printf("%s", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n, sqrtn;
map<int,ll> sorted;
int arr[1000000];
char str[1000000 + 1];
struct trnd {
	int ind; int dat;
};
typedef struct trnd trnd;
trnd tree[4 * 1000000];
trnd neg;
ll * ptrs[1000000];


trnd xmax(trnd a, trnd b){
	return (a.dat >= b.dat) ? a : b;
}
//#define xmax(a,b) (a.dat >= b.dat) ? a : b

void buildTree(int l, int r, int p){
	int mid;
	if (l >= r){
		tree[p].dat = arr[l];
		tree[p].ind = l;
	} else {
		mid = (l+r)/2;
		buildTree(l, mid, 2*p);
		buildTree(mid+1, r, (2*p)+1);
		tree[p] = xmax( tree[2*p] , tree[(2*p)+1] );
	}
}

trnd query(int nd, int l, int r, int p, int q) {
    if (r < p || l > q)
        return neg;
    else if (p <= l && q >= r)
        return tree[nd];
    int mid = (l+r)/2;
    return xmax(query(2*nd, l, mid, p, q), query((2*nd)+1, mid+1, r, p, q));
}

trnd simpleMin(int l, int r){
	int mx=0, mxi, i;
	for (i=l; i<=r; i++)
		if (arr[i] > mx){
			mx = arr[i]; mxi = i;
		}
	trnd x; x.dat = mx; x.ind = mxi;
	return x;
}

void makeSub(int l, int r){
	if (r==0 || l==n || l==r)
		return;
	trnd x;
	if ((r-l) > sqrtn)
		x = query(1, 0, n-1, l, r-1);
	else
		x = simpleMin(l, r-1);
	int mxi = x.ind;

	//sorted[x.dat] += ( ((ll) r-mxi) * ((ll) mxi-l+1) );
	*ptrs[x.ind] += ( ((ll) r-mxi) * ((ll) mxi-l+1) );

	makeSub(l, mxi);
	makeSub(mxi+1, r);
}

int main(){
	int t, i, m, j, sptr=0;
	//ios_base::sync_with_stdio(0);
	scanf("%d %d", &n, &m);

	ll limit = ((ll) n * (ll) (n+1))/2;
	sqrtn = sqrt(n);

	for (i=0; i<n; i++)
		scanf("%d", arr+i);
	
	for (i=0; i<n; i++){
		ptrs[i] = &(sorted[arr[i]] = 0);
		//ptrs[i] = &sorted[arr[i]];
	}

	neg.dat = -1; neg.ind = 0;
	buildTree(0, n-1, 1);
	makeSub(0,n);

	ll csz = 0;
	map<int,ll>::reverse_iterator mmrit;

	for (mmrit = sorted.rbegin(); mmrit != sorted.rend(); mmrit++){
		mmrit->second += csz;
		csz = mmrit->second;
	}

	char sign, player, temp;
	int x;
	ll ans;
	map <int,ll>::iterator mit;
	while (m--){
		scanf("%c%c%c%d%c%c", &temp, &sign, &temp, &x, &temp, &player);
		if (sign == '>'){
			mit = sorted.upper_bound(x);
			if (mit == sorted.end())
				ans = 0;
			else
				ans = mit->second;
		} else if (sign == '<'){
			mit = sorted.lower_bound(x);
			if (mit == sorted.end())
				ans = limit;
			else
				ans = limit - mit->second;
		} else {
			mit = sorted.find(x);
			if (mit != sorted.end()){
				ans = mit->second;
				mit++;
				if (mit != sorted.end())
					ans -= mit->second;
			} else
				ans = 0;
		}

		//printf("%lld\n", ans);
		if (ans % 2)
			str[sptr++] = player;
		else
			str[sptr++] = (player=='C' ? 'D' : 'C');
	}

	str[sptr] = '\0';
	printf("%s", str);
	return 0;
}

/*
3 5
1 2 3
> 1 D
< 2 C
= 3 D
> 4 C
< 5 D
*/