#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);

	int i;
	unsigned long n;
	for (i=0; i<t; i++){
		scanf("%lu", &n);
		printf("%lu\n", n+1);
	}
}