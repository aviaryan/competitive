#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int n,k,t;
	scanf("%d %d", &n, &k);

	int cts[100001] = {0};

	int i;
	for (i=0; i<n; i++) scanf("%d", &t), cts[t]++;

	return 0;
}