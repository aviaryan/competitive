#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


ll pollard_rho(ll n){
	if (n%2 == 0) return 2;
	ll x = rand() % n;
	ll y = x;
	ll c = rand() % n;
	ll g = 1;
	while (g==1){
		x = ((x*x)%n+c)%n;
		y = ((y*y)%n+c)%n;
		y = ((y*y)%n+c)%n;
		g = __gcd(abs(x-y),n);
		//ct++;
	}
	return g;
}

ll small_factor(ll n){ // n<100
   ll i = sqrt(n);
   for (; i>1; i--)
      if (n%i == 0)
         return i;
   return n;
}


ll solve(ll a, ll n){
	ll fc, fc2;

	if ( n==1 || a%n == 0 )
		return 1;

	while (n != 1)
	{
		fc = pollard_rho(n);
		if (fc == n)
			if (n<=100){
				fc = small_factor(n);
				n = n/fc;
				if (a%fc != 0) return 0; //cout << fc << " ";
				if (fc==n)
					break;
				else
					continue;
			} else {
				cout << n;
				break;
			}

		n = n/fc;
		while (n%fc == 0) n=n/fc;
		
		if (fc <= 100)
			if ((fc2 = small_factor(fc)) != fc){
				n = n * (fc/fc2);
				fc = fc2;
			}

		if (a%fc != 0) return 0; //cout << fc << " ";
	}

	return 1;
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
	return 0;
}