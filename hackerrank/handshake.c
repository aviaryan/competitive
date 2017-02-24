#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	int i;
	unsigned long long n;
	for (i=0; i<t; i++){
		scanf("%llu", &n);
		printf("%llu\n", n*(n-1)/2);
	}
}
