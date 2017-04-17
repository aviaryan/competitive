#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t,n,i,j,k,m,procnum,lt;
	scanf("%d", &t);
	int a[6];
	int palnums[900], pind=0;

	for (i=1; i<10; i++) 	// enum all possible numbers
		for (j=0; j<10; j++)
			for (k=0; k<10; k++){
				procnum = 100000*i + 10000*j + 1000*k + 100*k + 10*j + i;
				lt = ceil( sqrt(procnum) );

				for (m=101; m<=lt;m++){ // all possible divistors
					if (procnum%m == 0)
						if ( (procnum/m) < 1000 ){
							palnums[pind++] = procnum;
						}
				}

			}

	for (; t>0; t--){
		scanf("%d", &n);
		for (i=0; i<900; i++){
			if  ( palnums[i] > n )
				break;
			lt = palnums[i];
		}
		printf("%d\n", lt);
	}  
    return 0;
}
