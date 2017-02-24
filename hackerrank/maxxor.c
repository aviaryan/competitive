#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
	int max=0;
	int i,j,k;

	for (i=l; i<=r; i++){
		for (j=l+1; j<=r; j++){
			k = i ^ j;
			max = (k>max) ? k : max;
		}
	}

	return max;

}


int main() {
    int res;
    int _l;
    scanf("%d", &_l);
    
    int _r;
    scanf("%d", &_r);
    
    res = maxXor(_l, _r);
    printf("%d", res);
    
    return 0;
}
