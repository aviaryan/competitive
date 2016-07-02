#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

// cos graph dont cut each other

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int main(){
	int t;
	int s,c,k,i;
	scanf("%d", &t);

	while (t--){
		unsigned long long ans=0, temp;
		scanf("%d %d %d", &s, &c, &k);

		for (i=0; i<s; i++){
			temp = s-i; // this many sine graphs pass
			if (i>0){
				// 1 less than cos graph is symm with a sin graph - its actually hits all new parts of it
				if (c >= i) // all graphs of cos less than sin coefficient cuts sin graph but new parts cut by the highest coff of cos
					temp++;
			}
			if (temp>=k)
				ans += (i==0) ? 3 : (ull) pow(2, i); // these many new points were calculated for
		}

		if (k==1){ // in k=1, some coses more than s will be left out
			for (i=(s==0 ? 1 : s); i<=c; i++)
				ans += (ull) pow(2, i);
		}

		printf("%llu\n", ans);
	}
	return 0;
}