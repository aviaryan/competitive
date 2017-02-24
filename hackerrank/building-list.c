#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t, n, i, j, k;
    scanf("%d", &t);
    char s[16];
    char so[16];
 	char *sptr;

    for (;t>0;t--){
    	scanf("%d", &n);
    	scanf("%s", s);

    	for (i=0; i<n; i++){
    		sptr = &s[i];
    		so[0] = '\0';
    		for (j=i; j<n; j++){
    			so[j-i] = sptr[j-i];
    			so[j-i+1] = '\0';
    			printf("\n%s", so);
    		}
    	}

    }

    return 0;
}
