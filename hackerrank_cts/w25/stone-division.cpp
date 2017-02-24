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
bool globFwin;

// 1 + 0 = first wins
// 1 + even * something = first wins
// 1 + something * 0 = first wins

bool has_no_factors(ll num){
	bool ans = true;
	int i;
	for (i=0; i<m; i++)
		if (num % arr[i] == 0){
			ans = false;
			break;
		}
	return ans;
}

void solve(ll num, ll sofar){
	if (globFwin) 
		return;
	bool vs = false;
	int i;
	for (i=0; i<m; i++){
		if (num % arr[i] == 0){
			vs = true;
			solve(num / arr[i], sofar + (n/num));
		}
	}
	if (!vs){
		if (sofar % 2 == 1){
			// cout << sofar;
			globFwin = true;
		}
	}
}

bool solve2(ll num, bool turn){
	bool ans = !turn;
	int i;
	for (i=0; i<m; i++){
		if (num % arr[i] == 0){
			if (turn){
				if (solve2(num / arr[i], !turn)){
					ans = true; break;
				}
			} else {
				if (!solve2(num / arr[i], !turn)){
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
	bool fwin = false;
	for (i=0; i<m; i++){
		if (n % arr[i] == 0){
			if (n == arr[i] || arr[i] % 2 == 0 || has_no_factors(n / arr[i])){
				fwin = true;
				break;
			}
		}
	}

	if (fwin)
		cout << "First";
	else {
		globFwin = false;
		globFwin = solve2(n, true);
		if (globFwin)
			cout << "First";
		else
			cout << "Second";
	}

	return 0;
}