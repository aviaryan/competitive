#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

#define ull unsigned long long
#define ll long long
#define MC 1000000007

ll pow2_mod(int p){
	ll t = p/30;
	ull az = 1;
	while (t--){
		az *= (ull) pow(2,30);
		az %= MC;
	}
	az *= (ull) pow(2, p%30);
	return (ll) (az%MC);
}

int main(){
	ll t, k, j, tt, cases0, cases1;
	scanf("%lld", &t);

	long long nums[101] = {0}, i, freq[128] = {0};
	for (i=0; i<t; i++){
		scanf("%lld", &k);
		nums[k]++;
	}

	for (i=0; i<101; i++){
		if (nums[i] == 0)
			continue;

		ll tmp[128] = {0};
		cases0 = pow2_mod(nums[i]-1)-1; // for even, zero on xor
		cases1 = cases0+1; // for odd , same i

		for (j=0; j<128; j++)
			if (freq[j] > 0){
				tmp[ j^i ] = (tmp[j^i] + cases1*freq[j]) %MC;
				tmp[j] = (tmp[j] + cases0*freq[j]) %MC; // j^0
			}

		// add individual subsets like 111, 11, 11, 1
		tmp[0] += cases0;
		tmp[i] += cases1;

		for (j=0; j<128; j++)
			freq[j] = (freq[j] + tmp[j])%MC;
	}

	// freq counted , out result
	unsigned long long res=0;
	for (j=0; j<128; j++){
		if (freq[j]>1){
			res += freq[j]*(freq[j]-1)/2;
			res %= MC;
		}
	}

	printf("%llu", res);
	
	return 0;
}