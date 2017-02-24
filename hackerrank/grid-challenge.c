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

void countingsort(int n, char * s){
	int a[26] = {0};
	int i, j;
	for (i=0; i<n; i++)
		a[ (int) s[i] - 97 ]++;
	int c=0;
	for (i=0; i<26; i++)
		for (j=0; j<a[i]; j++)
			s[c++] = (char) i+97;
}

int main(){
	int t, n, pre, i, j;
	char ch;
	scanf("%d", &t);

	while (t--){
		scanf("%d%c", &n, &ch);
		char str[n][n+1];
		for (i=0; i<n; i++){
			scanf( "%s%c", str[i], &ch );
			countingsort(n, str[i]);
		}

		for (i=0; i<n; i++){
			pre = 96;
			for (j=0; j<n; j++){
				if (str[j][i] >= pre)
					pre = str[j][i];
				else
					break;
			}
			if (j != n)
				break;
		}
		if (i != n) printf("NO\n"); else printf("YES\n");
	}
	return 0;
}