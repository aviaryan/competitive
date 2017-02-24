#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n,m;
    scanf("%d %d", &n, &m);
	
	char sarr[n][m+1];

	int i;
	for (i=0; i<n; i++)
		scanf("%s", sarr[i]);

	int j, k, max=0, cc, cur, nummax=0;
	for (i=0; i<n-1; i++){
		for (j=i+1; j<n; j++){ // both strs got
			cur = 0;
			for (k=0; k<m; k++){
				cc = ( ( sarr[i][k] == '1' ) ? 1 : 0 ) + ( ( sarr[j][k] == '1' ) ? 1 : 0 );
				if (cc>0)
					cur++;
			}
			if (cur>max){
				nummax = 0;
				max = cur;
			}
			if (cur == max){
				nummax++;
			}
		}	
	}

	printf("%d\n%d", max, nummax);

    return 0;
}
