#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007

int main(){
	int t
	ull b,w,x,y,z;
	scanf("%d", &t);
	int fs;

	while (t--){
		scanf("%llu %llu %llu %llu %llu", &b, &w, &x, &y, &z);
		fs = 0;
		if (x+z < y || y+z < x) fs = 1;
		if (fs == 1){
			if (x>y)
				printf("%llu\n", w*y + b*(y+z));
			else
				printf("%llu\n", b*x + w*(x+z));
		} else
			printf("%llu\n", b*x + w*y);
	}
	return 0;
}