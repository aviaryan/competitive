#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ten97 1000000007

int min(int a, int b){ return a>b ? b : a; }
int max(int a, int b){ return a>b ? a : b; }

int main(){
	int t;
	scanf("%d", &t);
	char str[5];
	int n,p;

	while (t--){
		scanf("%d %s %d", &n, str, &p);
		if (strcmp(str, "odd") == 0)
			printf("%d\n", 2*p);
		else
			printf("%d\n", 2*p-1);
	}
	return 0;
}