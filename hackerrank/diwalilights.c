#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t, md, di,i;
	long n;
	scanf("%d", &t);
	unsigned long long res;

	for (;t>0;t--){
		scanf("%ld", &n);
		res = 1;
		md = n % 10;
		di = n /10;
		res = res*pow(2,md);
		res = res%100000;

		for (i=0; i<di; i++){
			res = res * 1024;
			res = res%100000;
		}

		if (res==0)
			res = 99999;
		else 
			res-=1;

		printf("%llu\n", res);
	}
}
