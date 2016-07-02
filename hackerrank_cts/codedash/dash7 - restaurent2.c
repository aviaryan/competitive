#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t;
	scanf("%d", &t);
	int l,b,sq, i, mn, pd;

	for (;t>0;t--){
		scanf("%d %d", &l, &b);
		mn = l;
		pd = l*b;
		if (mn>b)
			mn = l;
		for (i=mn; i>0; i--){
			if ( pd % (i*i) == 0 ){
				if ( (l%i) == 0 && (b%i) == 0 ){
					printf("%d\n", pd / (i*i) );
					break;
				}
			}
		}
	}   
    return 0;
}
