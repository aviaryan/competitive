#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int GCD(long a,long b) {
   return (b==0) ? a : GCD(b, a%b);
}

int main() {
	int k;
	scanf("%d", &k);

	int n, i, j, s; 
	long arr[100];
	for (;k>0;k--){
		s = 0;
		scanf("%d", &n);
		for (i=0; i<n; i++)
			scanf("%lu", arr+i);
		if (arr[0] == 1)
			printf("YES\n");
		else {
			// if 2 hcf 1, then all is done.
			for (i=0; i<n; i++)
				for (j=i+1; j<n; j++)
					if ( GCD(arr[i] , arr[j]) == 1 ){
						s = 1;
						break;
					}

			printf("%s\n", (s==1) ? "YES" : "NO");
		}
	}
     
    return 0;
}
