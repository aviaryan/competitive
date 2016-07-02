#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int t;
	scanf("%d", &t);
	int arr[1000001] = {0};
	int i, k;

	for (i=0; i<t; i++) scanf("%d", &k), arr[k]++;

	for (i=0; i<1000001; i++) {
		while (arr[i]--)
			printf("%d\n", i);
	}

	return 0;
}