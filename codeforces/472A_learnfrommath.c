#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int t, k;
	scanf("%d", &t);

	if (t%2 == 0){
		printf("%d %d", 4, t-4);
	} else {
		k = (t/2)/3; // catch 3 times under t/2
		if (k%2 == 0) // if 3 times is even, it wanna be odd for odd 3*
			k++;
		k *= 3;
		printf("%d %d", k, t-k); // t-k is even ! hurray
	}
	return 0;
}