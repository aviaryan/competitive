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
	int t, i, a, b, s;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> a >> b;
		s = 0;
		while (a > b){
			a = a/2;
			s++;
		}
		while ((a & (a-1)) != 0){
			a = a/2;
			s++;
		}
		//cout << s << endl;
		s += ( log( b/a ) / log(2) );
		cout << s << endl;
	}

	return 0;
}