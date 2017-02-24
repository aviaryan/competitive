#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPalindrome(char *s, int len){
	int i;
	for (i=0; i<(len/2); i++)
		if ( s[i] != s[len-i-1] )
			return 0;
	return 1;
}

// 

int main() {

	int t, l;
    scanf("%d", &t);
    char str[9];
    double ans;

    for (;t>0;t--){
    	scanf("%s", str);
    	l = strlen(str);
    	ans = 0;

    	if ( isPalindrome(str, l) == 1 ){
    		printf("%lf\n", ans);
    		continue;
    	}



    }
    return 0;
}
