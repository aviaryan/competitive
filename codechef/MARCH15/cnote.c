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
	int t;
	scanf("%d", &t);
	int x,y,n,k,p,c,i,s;

	while (t--){
		scanf("%d %d %d %d", &x, &y, &k, &n);
		x -= y;
		s = 0;
		for (i=0; i<n; i++){
			scanf("%d %d", &p, &c);
			if (c<=k)
				if (p>=x)
					s = 1, k=-1;
		}
		printf("%s\n", s==1 ? "LuckyChef" : "UnluckyChef");
	}
	return 0;
}