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


int solve_odd(int * mp, int d){
	int i, s=0, d2 = d/2;
	for (i=0; i<201; i++){
		s += mp[i];
		if (s > d2) break;
	}
	return i*2;
}

int solve_even(int * mp, int d){
	int i, s=0, d2=d/2, f1 = -1, f2;
	for (i=0; i<201; i++){
		s += mp[i];
		if (s >= d2 && f1 == -1)
			f1 = i;
		if (s > d2){
			f2 = i; break;
		}
	}
	return f1 + f2;
}

int main(){
	int t, i, n, d;
	ios_base::sync_with_stdio(0);
	cin >> n >> d;
	int arr[n+1], mp[201] = {0}, ans=0;
	int med;
	for (i=1; i<=n; i++){
		cin >> arr[i];
		if (i > d){
			if (i > d+1)
				mp[arr[i-d-1]]--;
			med = (d%2 == 0) ? solve_even(mp, d) : solve_odd(mp, d);
			if (arr[i] >= med) ans++;
		}
		mp[arr[i]]++;
	}
	cout << ans;
	return 0;
}