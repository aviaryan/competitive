#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

typedef long long ll;
ll stock_prices[50000];

ll solve(ll lp){
	if (lp < 1)
		return 0;
	ll ld = stock_prices[lp];
	ll i, find=-1;
	ll price=0;
	for (i=lp-1 ; i>=0; i--)
		if (stock_prices[i] > ld){
			find = i;
			break;
		} else 
			price += stock_prices[i];
	find++;
	return ((lp-find)*ld - price) + solve(find-1);
}

int main(){
	int t, in;
	scanf("%d", &t);

	ll n, i;
	while (t--){
		scanf("%lld", &n);
		for (i=0; i<n; i++)
			scanf("%lld", &stock_prices[i]);
		printf("%lld\n", solve(n-1));
	}

	return 0;
}