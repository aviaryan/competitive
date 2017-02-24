#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

int min(int a, int b){ return a>b ? b : a; }
int max(int a, int b){ return a>b ? a : b; }

int main(){
	int t;
	scanf("%d", &t);
	int h1,m1,s1,h2,m2,s2;
	char tc;

	while (t--){
		scanf("%d %c %d %c %d", &h1, &tc, &m1, &tc, &s1);
		scanf("%d %c %d %c %d", &h2, &tc, &m2, &tc, &s2);
		// hrs 6-9 blackout
		int ans=0;
		if (h2>h1){
			
		}
	}
	return 0;
}