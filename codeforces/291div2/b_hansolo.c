#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include <stdbool.h>

struct slopes {
	double slope;
	bool v;
};

int main(){
	int n,x0,y0;
	scanf("%d %d %d", &n, &x0, &y0);

	int i,x,y, ninetyslope=0;
	struct slopes mslopes[1000];
	for (i=0; i<n; i++){
		scanf("%d %d", &x, &y);
		if ( x0 - x != 0 ){
			mslopes[i].v = true;
			mslopes[i].slope = ( (double) (y0 - y) ) / ( (double) (x0 - x) );
		} else
			ninetyslope = 1, n--, i--;
	}

	int lines=0, j;
	if (ninetyslope == 1)
		lines = 1;

	double cslope;
	for (i=0; i<n; i++){
		if (mslopes[i].v == true){
			cslope = mslopes[i].slope;
			mslopes[i].v = false;
			for (j=(i+1); j<n; j++){
				if (mslopes[j].slope == cslope)
					mslopes[j].v = false;
			}
			lines++;
		}
	}

	printf("%d\n", lines);
	return 0;
}
