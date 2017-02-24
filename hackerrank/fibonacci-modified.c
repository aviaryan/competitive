#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

// no suppert for large ints

int main(){
	unsigned long long a,b,n;
	scanf("%llu %llu %llu", &a, &b, &n);

	unsigned long long i, pre = b*b + a;
	for (i=2; i<n; i++){
		a = b;
		b = pre;
		pre = pre*pre + a;
	}

	printf("%llu", b);
	return 0;
}