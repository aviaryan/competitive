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
	char str[1000001];

	while (t--){
		scanf("%s", str);
		// take O or Z both sides and then min
		// left side
		int curo=0, slen = strlen(str);
		long ans=0;
		for (i=0; i<slen; i++)
			if (str[i] == 'O'){
				ans += (i-curo);
				curo++;
			}
		// right side
		curo = slen-1;
		long ans2=0;
		for (i=slen-1; i>=0; i--){
			if (str[i] == 'O'){
				ans2 += curo - i;
				curo--;
			}
		}
		if (ans2<ans)
			ans = ans2;
		printf("%ld\n", ans);
	}
	return 0;
}