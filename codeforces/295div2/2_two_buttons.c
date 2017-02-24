#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int minsteps = 10000;
int n,m,z;
double lg;

void reachm(int cur, int steps){
	if (cur>m)
		return;
	else if (cur<1)
		return;
	else if (cur==m){
		if (steps < minsteps)
			minsteps = steps;
		return;
	}
	if (steps>minsteps)
		return;

	if ((cur*2) <= m){
		reachm(cur*2, steps+1);
	}
	
	if (cur==1)
		return;

	if ( m%(cur-1) == 0 ){
		z = m/(cur-1);
		if ((z & (z-1)) == 0){
			lg = log((double) z) / log(2.0); // nth power of 2
			reachm(m, steps+1+  ((int)lg) );
		} else
			reachm(cur-1, steps+1);
	} else
		reachm(cur-1, steps+1);

}

int main(){
	int isodd=0;
	scanf("%d %d", &n, &m);
	if (n>=m)
		printf("%d", n-m);
	else {
		if (m%2 != 0)
			isodd=1, m++;
		reachm(n, 0);
		printf("%d", (isodd==1) ? minsteps+1 : minsteps);
	}

	return 0;
}