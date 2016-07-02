#include <stdio.h>
#include <stdbool.h>

typedef unsigned long long lint;

lint GCD(lint a,lint b) {
   return (b==0) ? a : GCD(b, a%b);
}

lint LCM(lint a, lint b){
	return (a*b)/GCD(a, b);
}

main(){
	int t;
	scanf("%d", &t);
	int n,k, i;
	lint arr[30], lc, tlc, mx, mn;
	double avg, max;

	for (;t>0;t--){
		scanf("%d %d", &n, &k);
		lc = 1;

		for (i=0; i<n; i++){
			scanf("%llu", arr+i);
			lc = LCM(arr[i], lc);
		}

		for (i=0; i<k; i++){ // remove k holidays

			max = 0.0;
			// we use some average to find min proximity
			for (j=0; j<n; j++){
				// find lcm of 2 numbers - then distance is smaller number reached in (lcm/larger number) times
				avg = 0.0;
				for (k=0; k<n; k++){
					if (k==j)
						continue;
					tlc = LCM(arr[j], arr[k]);
					if (arr[j]>=arr[k])
						mx = arr[j], mn = arr[k];
					else
						mx = arr[k], mn = arr[j];
					avg += ((tlc/mn)-1)
				}

			}

		}

	}
}