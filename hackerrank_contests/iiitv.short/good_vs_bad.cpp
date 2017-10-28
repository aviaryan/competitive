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
	int t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> n;
	int arr[n];

	for (i=0; i<n; i++){
		cin >> arr[i];
	}
	ll ct = 0, oc = 0;

	for (i=n-1; i>=0; i--){
		if (arr[i] == 1) 
			oc = m(oc + 1LL);
		else {
			ct = m(ct + oc);
			oc = m(oc * 2LL);
		}
	}

	cout << ct << endl;

	return 0;
}