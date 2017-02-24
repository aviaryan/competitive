#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int t,n,i,s;
	scanf("%d", &t);
	int a[100000];
	unsigned long long skr, skl;

	for (;t>0;t--){
		scanf("%d", &n);
		skr = 0, skl = 0, s = 0;

		for (i=0;i<n;i++){
			scanf("%d", &a[i]);
			skr += a[i];
		}

		for (i=0;i<n;i++){
			if (i>0)
				skl += a[i-1];
			skr -= a[i];
			if (skl==skr){
				s = 1;
				break;
			}
		}

		printf("%s\n", s==1 ? "YES" : "NO");
	}
}
