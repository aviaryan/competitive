#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	long n, sk=0;
	int i;
	char str[1000];
	scanf("%ld", &n);
	long arr[100] = {0};
	for (;n>0;n--){
		scanf("%d", &i);
		arr[i]++;
		scanf("%s", str);
	}

	for (i=0; i<100; i++){
		sk = arr[i]+sk;
		printf("%ld ", sk);
	}
}
