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

	int maxsofar, lead, i, rcount;
	char str[1000001];
	while (t--){
		scanf("%s", str);
		lead = 0, maxsofar = 0, rcount = 0;

		for (i=0; i<strlen(str); i++){
			if (lead == 0)
				if (str[i] == 'R'){
					rcount++;
					continue;
				}
				else
					lead++;
			else
				if (str[i] == 'R')
					rcount++, lead--;
				else
					lead++;
			if (lead > maxsofar)
				maxsofar = lead;
			if (lead < 0)
				lead = 0;
		}

		printf("%d\n", rcount+ (maxsofar==0 ? -1 : maxsofar));
	}

	return 0;
}