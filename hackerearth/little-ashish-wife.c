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
	int t, n, k;
	scanf("%d", &t);
	char str[11 * 13000];

	while (t--){
		scanf("%d %d ", &n, &k);
		gets(str);
		printf("%s\n", n==k ? "Perfect husband" : (n>k ? "Lame husband" : "Bad husband"));
	}
	return 0;
}