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
	int t, i;
	scanf("%d", &t);
	int n,k, slens[101], s;
	char str[101];

	while (t--){
		scanf("%d %d", &n, &k);
		s = 1;
		for (i=0; i<101; i++) slens[i] = 0;
		for (i=0; i<n; i++) scanf("%s", str), slens[ strlen(str) ]++;

		for (i=0; i<101; i++)
			if (slens[i]%k != 0){
				s = 0;
				break;
			}
		printf("%s\n", s==1 ? "Possible" : "Not possible");
	}
	return 0;
}