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

ll arr[10];
ll m, n;

bool solve(ll num, bool turn){
	bool ans = !turn;
	int i;
	for (i=0; i<m; i++){
		if (num % arr[i] == 0){
			if (turn){
				if (solve(num / arr[i], !turn)){
					ans = true; break;
				}
			} else {
				if (!solve(num / arr[i], !turn)){
					ans = false; break;
				}
			}
		}
	}
	return ans;
}

int main(){
	ll t, i;
	ios_base::sync_with_stdio(0);
	cin >> n >> m;
	for (i=0; i<m; i++)
		cin >> arr[i];

	bool fwin = solve(n, true);
	if (fwin)
		cout << "First";
	else
		cout << "Second";

	return 0;
}