#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int bc, gc, slen;
char str[100001];

ull solve(int bs, int ty){
	int i, sb=0, sg=0;
	ull ans=0;

	while (1){
		for (i=sb; i<slen; i++)
			if (str[i] == 'B')
				if (i%2 != bs){
					sb = i;
					break;
				}
		if (i==slen)
			break;
		for (i=sg; i<slen; i++)
			if (str[i] == 'G')
				if (i%2 == bs){
					sg = i;
					break;
				}
		ans += (ty==0) ? 1 : abs(sb-sg); // for 2 also, do it in 1 step-swaps - no of steps taken will be same as the difference
		sb++;
		sg++;
	}

	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	int ty, i, bs;
	ull ans, ans2;

	while (t--){

		scanf("%d %s", &ty, str);
		slen = strlen(str);
		gc=0, bc=0;
		for (i=0; i<slen; i++)
			if (str[i] == 'B') bc++; else gc++;
		if (abs(bc-gc) > 1){
			printf("-1\n"); 
			continue;
		}

		if (bc == gc){
			ans2 = solve(0, ty);
			ans = solve(1, ty);
			if (ans2 < ans)
				ans = ans2;
		} else
			if (bc>gc)
				ans = solve(0, ty);
			else
				ans = solve(1, ty);

		printf("%llu\n", ans);
	}
	return 0;
}