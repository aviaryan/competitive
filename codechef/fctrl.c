#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int t, n, ct, i;
	scanf("%d", &t);
	long long p5;

	for (;t>0;t--){
		ct = 0;
		scanf("%d", &n);
		p5 = 1;
		for (i=1; i<15; i++){
			p5 *= 5;
			if (p5 > n)
				break;
			ct += n/p5;
		}
		printf("%d\n", ct);
	}
	return 0;
}