#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// not find digit - some other
int main() {

    int n,t;
    scanf("%d %d", &n, &t);

    int warr[n], i, j;
    for (i=0; i<n; i++)
    	scanf("%d", warr+i);

    int a,b,min=3;
    for (i=0; i<t; i++){
    	scanf("%d %d", &a, &b);
    	for (j=a; j<=b; j++){
    		if (warr[j] < min)
    			min = warr[j];
    	}
    	printf("%d\n", min);
    	min = 3;
    }
}
