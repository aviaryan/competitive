#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	long k;
	scanf("%ld", &k);
	unsigned long long n, res, thr, fiv, cmn;

	for (;k>0;k--){
		scanf("%llu", &n);
		res = 0;
		thr = (n-1)/3;
		res = 3*(thr)*(thr+1)/2;
		fiv = (n-1)/5;
		res += 5*(fiv)*(fiv+1)/2;
		cmn = (n-1)/15;
		res -= 15*(cmn)*(cmn+1)/2;
		printf("%llu\n", res);
	}
}