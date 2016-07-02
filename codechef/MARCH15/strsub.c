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
	ll j, l, r, ans;
	char str[100001];
	ll validtill[100000], tmp;
	int maxoverflow[100000];
	int ls;

	while (t--){
		scanf("%d %d %d ", &n, &k, &q);
		scanf("%s", str);

		memset(maxoverflow, -1, n*4);
		zc = 0, oc = 0, curind = 0, tmp=-1;
		for (i=0; i<n; i++){ // find no of valid subs a index can generate
			if (str[i] == '1')
				oc++;
			else zc++;
			if (zc > k || oc > k){
				if (curind==0){
					validtill[curind] = i-curind;
					tmp = validtill[curind]-1;
					for (j=0; j<=tmp; j++)
						maxoverflow[j] = 0;
				}
				else {
					validtill[curind] = validtill[curind-1] + i-curind;
					tmp = i-1;
					if (maxoverflow[tmp] == -1)
						maxoverflow[tmp] = curind;
				}
				if (str[curind] == '1') // subtract the first one
					oc--;
				else zc--;
				if (str[i] == '1') oc--; else zc--;
				i--; // rewind
				curind++;
			}
		}

		for (i=curind; i<n; i++) // remaining items in the end
			validtill[i] = validtill[i-1] + n-i;
		for (tmp=tmp+1; tmp<n; tmp++)
			maxoverflow[tmp] = curind;

		ls = -1;
		for (i=n-1; i>=0; i--){
			if (maxoverflow[i] == -1)
				maxoverflow[i] = ls;
			else
				ls = maxoverflow[i];
		}

		for (i=0; i<q; i++){
			scanf("%lld %lld", &l, &r);
			l--; r--;
			tmp = maxoverflow[r];
			ans = 0;
			
			if (tmp<l)
				tmp = l;
			else if (tmp != 0) // l to tmp-1
				ans += validtill[tmp-1] - (l==0 ? 0 : validtill[l-1]);
			// tmp to r
			ans += (r-tmp+1)*(r-tmp+2)/2;
			printf("%lld\n", ans);
		}
	}
	return 0;
}