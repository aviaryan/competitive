#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// gives tle

int main() {
	int t;
	scanf("%d", &t);
	int n, i, j, k, end=0;
	unsigned long long m, ts, bts, arr[100000], mx;

	for (;t>0;t--){
		scanf("%d %llu", &n, &m);
		ts = 0, end=0;
		for (i=0; i<n; i++){
			scanf("%llu", arr+i);
			arr[i] %= m;
			ts += arr[i];
			if (ts%m == (m-1))
				end=1;
		}

		bts = ts;
		mx = 0;
		if (end==1){
			printf("%llu\n", m-1);
			continue;
		}

		for (i=0; i<n; i++){

			if (i>0)
				bts -= arr[i-1];
			ts = bts;

			if (ts%m > mx){
				mx = ts%m;
				if (mx == (m-1)){
					end=1; 
					break;
				}
			}

			for (j=(n-1); j>i; j--){
				ts -= arr[j];

				if (ts%m > mx){
					mx = ts%m;
					if (mx == (m-1)){
						end=1; 
						break;
					}
				}
			}

			if (end==1)
				break;

		}

		if (end==1){
			printf("%llu\n", m-1);
			continue;
		}

		printf("%llu\n", mx);

	}
}
