#include "bits/stdc++.h"
#define MODULO 1000000007
#define LT 50000
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll arr[LT+1];
ll mods[LT+1];

ll gcd(ll a, ll b) {
   return (b==0) ? a : gcd(b, a%b);
}

int main(){
	printf("asdaf");
	int t, i, j;
	s(t);
	double maxx, temp;
	ll maxn, maxd, num, den, n, p, k;
	arr[0] = 0;
	printf("kdkk");
	
	while (t--){
		scanf("%lld %lld %lld", &n, &p, &k);
		maxx = 0;
		mods[i] = 0;
		printf("kasd");
		for (i=1; i<=n; i++){
			scanf("%lld", &arr[i]);
			mods[i] = (arr[i] + mods[i-1])%p;
		}
		printf("asdkaf");
		for (i=1; i <= (n-k+1); i++){
			j = i+k-1;
			while (j <= n){
				num = (mods[j] - mods[i-1] + p)%p;
				den = (j-i+1);
				temp = num / (double) den;
				if (temp >= maxx){
					maxn = num;
					maxd = den;
					maxx = temp;
				}
				j++;
			}
		}

		printf("--> %lld %lld\n", maxn, maxd);
		if (maxn % maxd == 0){
			maxn = maxx;
			maxd = 1;
		} else if (maxn != 0) {
			maxx = gcd(maxn, maxd);
			maxn /= maxx; maxd /= maxx;
		}
		printf("%lld %lld\n", maxn, maxd);
	}

	return 0;
}