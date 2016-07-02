#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int t;
	scanf("%d", &t);

	int n, i, k, maxcont, maxsofar, maxnoncont, maxe;

	for (;t>0;t--){
		scanf("%d", &n);
		maxcont = 0, maxnoncont = 0, maxsofar=0, maxe=-10001;
		for (i=0; i<n; i++){
			scanf("%d", &k);
			if (k>maxe)
				maxe = k;
			if (k>0)
				maxnoncont += k;
			maxsofar += k;
			if (maxcont < maxsofar)
				maxcont = maxsofar;
			if (maxsofar < 0)
				maxsofar = 0;
		}

		if (maxnoncont == 0)
			maxnoncont = maxe;
		if (maxcont == 0)
			maxcont = maxe;

		printf("%d %d\n", maxcont, maxnoncont);
	}
	return 0;
}