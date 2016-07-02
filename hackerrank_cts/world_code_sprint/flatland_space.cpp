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
	int t, i, n, m;
	cin >> n >> m;
	vector<int> v;
	for (i=0; i<m; i++){
		cin >> t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	int ans = *v.begin() - 0;
	vector<int>::iterator vi;
	int d, prev = *v.begin();

	for (vi = ++v.begin(); vi != v.end(); vi++){
		d = (*vi - prev)/2;
		ans = max(ans, d);
		prev = *vi;
		//cout << ans << endl;
	}
	ans = max(ans, n-1 - prev);

	cout << ans << endl;
	return 0;
}