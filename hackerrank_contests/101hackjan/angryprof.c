#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d", &t);
    int n, k, i, j, nbk;

    for (;t>0;t--){
    	scanf("%d %d", &n, &k);
    	nbk = n;
    	for (i=0; i<n; i++){
    		scanf("%d", &j);
    		if (j>0)
    			nbk--;
    	}
    	if (nbk>=k)
    		printf("NO\n");
    	else
    		printf("YES\n");
    }
    return 0;
}
