#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t; 
	scanf("%d", &t); 
	unsigned long long a,b, s, z, ct;

	for (;t>0;t--){
		scanf("%llu %llu", &a, &b);
		ct = 0;
		s = sqrt(a);
		if ( s*s == a )
			ct++;
		z = s*s;
		z += 2*s + 1;
		while (z<=b && z>a){
			ct++;
			z += 2*(++s)+1;
		}
		printf("%llu\n", ct);
	}
    return 0;
}
