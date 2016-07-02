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
	int n, i;
	scanf("%d ", &n);
	char str[2*n - 1];
	gets(str);
	int k = 2*n - 2;

	int keys[140] = {0}, bln = 0;
	for (i=0; i<k; i++){
		if (i%2 == 0){
			keys[str[i]]++;
		} else {
			if (keys[str[i]+32])
				keys[str[i]+32]--;
			else
				bln++;
		}
	}

	printf("%d", bln);
	return 0;
}