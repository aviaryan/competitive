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
	int t, i, n, k, pi;
	ios_base::sync_with_stdio(0);
	cin >> n >> k;
	int cp=0, ans=0;

	for (i=0; i<n; i++){
		cin >> t;
		pi = 0; // prblm index
		while (t>0){
			cp++;
			if ( ( (pi+min(t,k))>=cp ) && ( cp>=(pi+1) ) )
				ans++;
			t-=k;
			pi+=k;
		}
	}

	cout << ans << endl;

	return 0;
}