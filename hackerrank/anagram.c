#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// 97
int main() {

    int k, slen, i, ct, l;
    scanf("%d", &k);
    char str[10001];
    char s2[5001];
    int alp[26] = {0};
    char *sptr, *rptr;

    for (;k>0;k--){
    	scanf("%s", str);
    	if ( (slen = strlen(str) ) % 2 != 0 ){
    		printf("-1\n");
    		continue;
    	}

    	sptr = &str[slen/2];
    	strcpy(s2, sptr);

    	ct = 0;
    	for (i=0; i<slen/2; i++){
    		rptr = strchr(s2, (int) str[i] );
    		if (rptr == NULL)
    			ct++;
    		else {
    			rptr[0] = '-';
    		}
    	}
    	printf("%d\n", ct);

    }   
    return 0;
}