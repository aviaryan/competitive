#include "bits/stdc++.h"
#define endl '\n'
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

pair <int,ull> arr[100000+1];
ull m;

ull md(ull a){
	return a%m;
}

bool cmp(pair<int,ull> a, pair<int,ull> b){
	return a.second < b.second;
}

int main(){
	int t, i, n, ci;
	ull cw, ans, p_cw;
	int jp, p_jp;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> n >> m;
		arr[0] = make_pair(0,0);
		for (i=1; i<=n; i++){
			cin >> arr[i].second;
			arr[i].second = md(arr[i].second + arr[i-1].second);
			arr[i].first = i;
		}
		sort( arr+1 , arr+n+1 , cmp );
		
		ans = 0;
		p_cw = -1; // some large positive number as ull

		for (i=1; i<=n; i++){
			ci = arr[i].first;
			cw = arr[i].second;
			ans = max(ans,cw); // 0 case

			if (p_cw == cw){
				jp = p_jp;
			} else {
				jp = i-1;
				while (arr[jp].second == cw) jp--;
			}

			if (arr[jp].first > ci)
				ans = max(ans,md(m+arr[jp].second-cw));

			p_cw = cw; p_jp = jp;
		}

		cout << ans << endl;
	}

	return 0;
}