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
	int n,k,q;
	int zc, oc, curind;
	ull j, l, r, ans, lent;
	char str[100001];
	int validtill[100000];
	ull totlens[100000];

	while (t--){
		scanf("%d %d %d ", &n, &k, &q);
		scanf("%s", str);

		zc = 0, oc = 0, curind = 0;
		for (i=0; i<n; i++){ // find no of valid subs a index can generate
			if (str[i] == '1')
				oc++;
			else zc++;
			if (zc > k || oc > k){
				validtill[curind] = i-curind;
				if (str[curind] == '1') // subtract the first one
					oc--;
				else zc--;
				if (str[i] == '1') oc--; else zc--;
				i--; // rewind
				curind++;
			}
		}

		for (i=curind; i<n; i++) // remaining items in the end
			validtill[i] = n-i;

		for (i=0; i<n; i++)
			printf("%d ", validtill[i]);

		for (i=0; i<q; i++){
			scanf("%llu %llu", &l, &r);
			ans = 0;
			l--; r--;
			for (lent=r-l+1; lent>0; lent--){
				if (validtill[l] >= lent){
					ans += (lent*(lent+1)/2); // n(n+1)/2 - all future subs cover all of length
					break;
				} else
					ans += validtill[l]; //-j+1;
				l++;
			}
			printf("%llu\n", ans);
		}
	}
	return 0;
}