#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int t, a, b, c=0, d=0;
	scanf("%d", &t);
	int mxlead=0, wholead;

	while (t--){
		scanf("%d %d", &a, &b);
		c+=a, d+=b;
		if (abs(c-d) > mxlead) wholead = c>d ? 1 : 2, mxlead = abs(c-d);
	}

	printf("%d %d", wholead, mxlead);
	return 0;
}