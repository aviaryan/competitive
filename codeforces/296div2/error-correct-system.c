#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b
#define MODULO 1000000007

int main(){
	int t, ans=0, i, j;
	scanf("%d ", &t);
	char s1[t+1], s2[t+1];
	scanf("%s %s", s1, s2);
	
	int e1[26] = {0}, e2[26] = {0};
	int p1[26][26];

	for (i=0; i<26; i++)
		for (j=0; j<26; j++)
			p1[i][j] = 0;

	for (i=0; i<t; i++){
		if (s1[i] != s2[i]){
			e1[ (int) s1[i] - 97 ] = i+1;
			e2[ (int) s2[i] - 97 ] = i+1;

			p1[ (int) s1[i] - 97 ][(int) s2[i] - 97] = i+1;
			ans++;
		}
	}

	// find two
	int c=0, indc1[26], indc2[26], matches[26];
	for (i=0; i<26; i++){
		if (e1[i] != 0)
			if (e2[i] != 0){
				indc1[c] = e1[i];
				indc2[c] = e2[i];
				matches[c] = i;
				c++;
			}
	}

	if (c>1){
		int found=0, p, q;
		for (i=0; i<c; i++){
			for (j=0; j<c; j++){
				if (j==i)
					continue;
				if ( p1[ matches[i] ][ matches[j] ] > 0 )
				if ( p1[ matches[j] ][ matches[i] ] > 0 ){
					found = 1;
					p = p1[ matches[i] ][ matches[j] ];
					q = p1[ matches[j] ][ matches[i] ];
					break;
				}
			}
			if (found==1)
				break;
		}
		if (found){
			printf("%d\n", ans-2);
			printf("%d %d", p, q);
			return 0;
		} else
			c = 1;
	}

	printf("%d\n", ans-c);
	if (c==0)
		printf("-1 -1");
	else
		if (c==1)
			printf("%d %d", indc1[0], indc2[0]);
		else
			printf("%d %d", indc1[0], indc1[1]);

	return 0;
}