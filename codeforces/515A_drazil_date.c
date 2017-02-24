#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int a,b,t;
	scanf("%d %d %d", &a, &b, &t);
	int z = abs(a) + abs(b);
	if (t < z)
		printf("No");
	else
		if ((t-z) % 2 == 0)
			printf("Yes");
		else
			printf("No");
	return 0;
}