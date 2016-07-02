#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	long n;
	int i;
	scanf("%ld", &n);
	long arr[100] = {0};
	for (;n>0;n--){
		scanf("%d", &i);
		arr[i]++;
	}

	for (i=0; i<100; i++){
		for (n=0; n<arr[i]; n++)
			printf("%d ", i);
	}
}
