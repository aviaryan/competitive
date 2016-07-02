#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t,i;
	long n;
	scanf("%d", &t);

	for (i=0; i<t; i++){
		scanf("%lu", &n);
		printf("%lu\n", (n%2==0) ? n*n/4 : (n/2)*(n/2+1));
	}
    return 0;
}
