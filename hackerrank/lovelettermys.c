#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    int i,j,l,m, ul, ll, diff, dtot;
    char str[10000];

    for (i=0; i<n; i++){
    	scanf("%s", str);
    	l = strlen(str);
    	m = l/2;
    	dtot = 0;

    	if (l%2 == 0){
    		for (j=0; j<m; j++){
    			ul = (int) str[m-j-1];
    			ll = (int) str[m+j];
    			diff = ul-ll;
    			if (diff<0)
    				diff = -1 * diff;
    			dtot += diff;
    		}
    	} else {
    		for (j=0; j<m; j++){
    			ul = (int) str[m-j-1];
    			ll = (int) str[m+j+1];
    			diff = ul-ll;
    			if (diff<0)
    				diff = -1 * diff;
    			dtot += diff;
    		}
    	}
    	printf("%d\n", dtot);
    }
}
