#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int n;
	scanf("%d", &n);
	int zf = 0, i = 1, j;
	while (zf < n){
		i++;
		j = i;
		while (j%5 == 0){
			zf++;
			j = j/5;
		}
	}
	printf("%d", i);
    return 0;
}