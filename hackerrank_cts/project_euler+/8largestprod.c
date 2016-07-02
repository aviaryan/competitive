#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t,i,n,k,j;
	scanf("%d", &t);
	long prod,maxp=0;
	char str[1001];

	for (;t>0;t--){
		scanf("%d%d", &n, &k);
		scanf("%s", str);

		// init get
		maxp=0;

		for (i=0; i<=(n-k); i++){

			prod = 1;
			for (j=i; j<(i+k); j++){
				prod *= (int) str[j] - 48;
			}
			if (prod>maxp)
				maxp = prod;	

		}

		printf("%ld\n", maxp);
		str[0] = '\0';
	}
}
