#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;

ll ct=0;

ll solve(ll a, ll b){
	ll hcf;
 
	if ( (b==1) || (a%b == 0) )
		return 1;
	if ( a==1 ) // now its not possible
		return 0;
 	
 	while (1){
 		hcf = __gcd(a, b);
 		if (hcf == b)
 			return 1;
 		else if (hcf == 1)
 			return 0;
 		b = b/hcf;
 	}
}
 
int main(){
	ll t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	ll ans,a,b;
	char s1[] = "Yes";
	char s2[] = "No";
 
	while (t--){
		cin >> a >> b;
		ans = solve(a,b);
		if (ans)
			printf("%s\n", s1);
		else
			printf("%s\n", s2);
	}
	//cout << endl << ct;
	return 0;
} 