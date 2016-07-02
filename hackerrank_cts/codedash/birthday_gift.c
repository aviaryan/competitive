#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// 1015 - sqrt 32
#define SZ 32

struct timecell {
	int x; // row
	int y;
};

int main() {

    int t;
    scanf("%d", &t);

    int i, j, ci, cj, csize, temp;
    int mx[SZ][SZ];
    struct timecell pos[SZ*SZ];

    for (i=0; i<SZ; i++)
    	for (j=0; j<SZ; j++)
    		mx[i][j] = 0;

    // fill it
    ci = 1, cj = 1, csize=1;
    for (i=1; i<=(SZ*SZ); i++){

    	mx[ci - 1][cj - 1] = i;
    	pos[i-1].x = ci;
    	pos[i-1].y = cj;

    	temp = sqrt(i);
    	if ( temp*temp == i )
    		csize++;
    	

    	if ( (mx[ci+1 -1][cj -1] == 0) && (ci<csize) )
    		ci++;
    	else if ( (mx[ci -1][cj+1 -1] == 0) && (cj<csize) )
    		cj++;
    	else if ( (mx[ci-1 -1][cj -1] == 0) && (ci!=1) )
    		ci--;
    	else if ( (mx[ci -1][cj-1 -1] == 0) && (cj!=1) )
    		cj--;
    }

    for (i=0; i<t; i++){
    	scanf("%d", &j);
        if (j>1015)
            printf("wrong");
        else
    	   printf("Case %d: %d %d\n", i+1, pos[j-1].y, pos[j-1].x);
    }

    return 0;
}
