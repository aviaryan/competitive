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

	bool status[n];
	for (i=0; i<n; i++){
		cin >> t;
		status[i] = (t==1) ? false : true;
	}

	i = 0;
	int steps = 0;
	while (true){
		if ( (i+2 >= n) || (!status[i+2]) ){
			steps ++;
			i++;
		} else {
			steps ++;
			i += 2;
		}
		if (i == n-1) break;
	}

	cout << steps << endl;

	return 0;
}