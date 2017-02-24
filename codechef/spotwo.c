#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007

ull Pow2Mod(ull n){
    ull ret = 1;
    ull a = 2;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

ull dec2bin(unsigned dec){
	unsigned mask = 1 << 31;
	int c, d=0, ind=0;
	ull ans=0;
	for (c=1; c<=32; c++){
		if (d==0)
			if ( dec & mask )
				d = 1;
		if (d==1)
			ans = ans*10 + (dec & mask ? 1 : 0);
		dec <<=1;
	}
	return ans;
}

int main(){
	int t, z;
	scanf("%d", &t);
	unsigned n;
	bool isodd;
	ull ans, fans;

	while (t--){
		scanf("%u", &n);
		isodd = (n%2);
		n/=2;
		ans = dec2bin(n);
		ans = Pow2Mod(ans);
		z = 20;
		fans = 1;
		while (z--){
			fans = fans * ans;
			fans %= MODULO;
		}
		if (isodd)
			fans = (fans*4) % MODULO;
		printf("%llu\n", fans);
	}
	return 0;
}