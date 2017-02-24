#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	int i;
	long a,b, j, k;

	for(i=0; i<t; i++){
		scanf("%lu %lu", &a, &b);
		// find sq
		j = sqrt(a);
		if (j*j != a)
			j = j+1;
		k = sqrt(b);
		printf("%d\n", k-j+1);
	}   
    return 0;
}
