#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

int main(){
	int n,m,i,g,p;
	scanf("%d %d", &n, &m);
	int sad=n+m;

	int b;
	scanf("%d", &b);
	sad-=b;
	bool boys[n];
	memset(boys, 0, n);
	for (i=0; i<b; i++)
		scanf("%d", &p), boys[p]=1;

	scanf("%d", &b);
	sad-=b;
	bool girls[m];
	memset(girls, 0, m);
	for (i=0; i<b; i++)
		scanf("%d", &p), girls[p]=1;

	b=0,g=0;
	bool workdone = 0;
	while (sad>0){
		if (boys[b])
			if (!girls[g])
				girls[g] = 1, workdone=1, sad--;
		if (girls[g])
			if (!boys[b])
				boys[b] = 1, workdone=1, sad--;
		b = (b+1) % n;
		g = (g+1) % m;
		if (b+g == 0){
			if (workdone == 0)
				break;
			workdone=0;
		}
	}

	if (sad==0)
		printf("YES");
	else
		printf("NO");

	return 0;
}