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


int main(){
	ll t, i, n, x1, y1, x2, y2;
	ios_base::sync_with_stdio(0);

	cin >> n >> x1 >> y1 >> x2 >> y2;
	ll xs[n], ys[n];
	ll x,y;

	for (i=0; i<n; i++){
		cin >> x >> y;
		xs[i] = x;
		ys[i] = y;
	}

	ll dis1[n], max_dis1 = 0;
	multimap <ll,int> dis2;

	for (i=0; i<n; i++){
		dis1[i] = (x1-xs[i])*(x1-xs[i]) + (y1-ys[i])*(y1-ys[i]);
		max_dis1 = max(max_dis1, dis1[i]);
		dis2.insert( make_pair( (x2-xs[i])*(x2-xs[i]) + (y2-ys[i])*(y2-ys[i]) , i ) );
	}

	// cout << max_dis1 << endl;

	multimap <ll,int>::reverse_iterator mit;
	ll ans = max_dis1, cur = 0, cur_r1 = 0;

	for (mit = dis2.rbegin(); mit != dis2.rend(); mit++){
		cur += mit->first;
		ans = min(cur, ans);
		cur = max(cur_r1, dis1[mit->second]);
		cur_r1 = cur;
	}
	// ans = min(max_dis1, ans);

	cout << ans << endl;
	return 0;
}