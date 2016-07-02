#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n, k, nc=0, t, maxp=1, diff;
	long sum=0;
	scanf("%d", &n);
	k = n;

	while (k>0){
		k = k/10;
		nc++;
	} // n of chars

	// calc class sum
	for (t=0; t<nc; t++){
		sum += 9 * ( (long) pow(10,t) ) * (t+1);
	}
	
	// calc max point
	for (t=0; t<nc; t++){
		maxp *= 10;
	}
	maxp-=1;

	// minus maxp and the num
	diff = maxp - n;
	sum = sum - ( nc * diff );
	printf("%d", sum);

    return 0;
}