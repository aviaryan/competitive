#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int k;
	scanf("%d", &k);
	int i;
	unsigned long long z=0,n;
	for (i=0; i<k; i++){
		scanf("%llu", &n);
		z+=n;
	}

	printf("%.1lf", (z%2==0) ? z/2 : z/2+0.5);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
