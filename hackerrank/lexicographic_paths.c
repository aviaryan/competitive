#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
faster lexo-
HHHVVV
count till VHHHVV
for H*(VHVHV) num of combinations - 5!/3!2! = 10
so 0-9 for that . 
k=10 = VHHHVV
for VVHHHV
we have V(H*)(HHVV) - 4!/2!2!
k = 16 for VVHHHV
*/

unsigned long long nfac(int n, int r){
	return (n<r) ? 1 : n*nfac(n-1, r);
}

int main() {
	int t, x, y, i, temp, mc, xc, yc;
	scanf("%d", &t);
	unsigned long long k, tk=0, otk, cmb, facterm;
	int c=0;
	int arr[20];

	for (;t>0;t--){
		scanf("%d %d %llu", &x, &y, &k);
		for (i=0; i<x; i++)
			arr[i] = 0;
		for (i=x; i<(y+x); i++)
			arr[i] = 1;

		otk = 0;
		mc=0;
		xc = 0;
		yc = 0;
		// TIP - use multiple time recursuive loop here
		while (k!=otk){

			c = 0; tk = otk;
			facterm = nfac(x-1-xc, 2);

			while (k>=tk){
				// build arr before this
				otk = tk;
				if (c!=0){
					temp = arr[c-1+mc]; // 1st term
					arr[c-1+mc] = arr[x+yc]; //first V term
					arr[x+yc] = temp;
					yc++;
				}
				cmb = nfac(x+y-c-1-mc, y-yc+1)/facterm;
				tk += cmb;
				c++;
			}

			if (c>1){
				mc += c; // if V added to top, 1st term pos increased
				xc++; 	// but x is const decrease of 1 on right side
			} else {
				mc++; xc++;
			}
		}

		for (i=0; i<(x+y); i++)
			printf("%c", ( arr[i] == 0 ) ? 'H' : 'V' );
		printf("\n");
	}

}
