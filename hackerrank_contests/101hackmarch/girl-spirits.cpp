#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, n, k, i, suc, cur=0, used=0;
	cin >> t;
	int maxmin;

	while (t--){
		cin >> n;
		cur = 0;
		used = 0;
		suc = 0;
		maxmin=0;

		for (i=0; i<n; i++){
			scanf("%d", &k);
			if (k < 0){
				if (k<maxmin)
					maxmin = k;
				if (cur+k < 0)
					if (used == 0)
						k = maxmin==0 ? -k : -2*maxmin+k, used = 1;
					else if (suc==0)
						suc = i+1;
			}
			cur += k;
		}

		if (suc==0)
			printf("She did it!\n");
		else
			printf("%d\n", suc);
	}

	return 0;
}