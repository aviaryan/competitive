#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// 1st down 2nd right, 3rd down ...

int main() {

    int t, i;
    scanf("%d", &t);
    unsigned long long srt, n, r, c, style;

    for (i=0;i<t;i++){
    	scanf("%llu", &n);
    	srt = sqrt(n);

    	if ( srt*srt == n ){
    		style = (srt%2);

    		if (style==1){
    			c = 1;
    			r = srt;
    		} else {
    			c = srt;
    			r = 1;
    		}

    	} else {
    		style = (srt%2);

    		if (style==0){ // take ex 5 - style = 0
    			c = srt+1;
    			r = n - (srt*srt);
    			if (r > c){
    				c = c - r%c;
    				r = srt+1;
    			}
    		} else { // take 10
    			r = srt+1;
    			c = n-(srt*srt);
    			if (c > r){
    				r = r - c%r;
    				c = srt+1;
    			}
    		}
    	}

    	printf("Case %d: %llu %llu\n", i+1, c, r);

    }

    return 0;
}
