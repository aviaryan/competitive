#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	// dir = 1 , down , right , up, left
	// for n=3  3 2 2 1 1
    int t, n, n1, i, j, sq, dir, x, y, cct, times, curl;
    scanf("%d", &t);
    int mx[100][100];

    for (;t>0;t--){
    	scanf("%d", &n);
    	sq = n*n;

    	x = -1, y = 0; // mx x y
    	dir = 1;
    	times = 1;
    	curl = n;
    	cct = 0;

    	n1 = n-1;

    	for (i=1; i<=sq; i++){
    		// init to zero

    		if (cct == curl){
    			dir++;
    			times++;
    			cct = 0;
    			if (dir>4)
    				dir = 1;
    			if (times==2){
    				curl--;
    				times = 0;
    			}
    		}

    		if (dir==1)
    			mx[++x][y] = i;
    		else if (dir==2)
    			mx[x][++y] = i;
    		else if (dir==3)
    			mx[--x][y] = i;
    		else if (dir==4)
    			mx[x][--y] = i;
    		cct++;

    	}

    	for (i=0; i<n; i++){
    		for (j=0; j<n; j++)
    			printf("%d ", mx[i][j]);
    		printf("\n\n");
    	}

    }

    return 0;
}
