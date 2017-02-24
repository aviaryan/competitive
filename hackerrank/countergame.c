#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sstrrev(int *s, int k){
	int i;
	int c;
	for (i=0; i<k/2; i++){
		c = s[i];
		s[i] = s[k-i-1];
		s[k-i-1] = c;
	}
}

int main() {
	int t, c, i, w, op, obc;
	scanf("%d", &t);
	int str[64];
	unsigned long long n,s;

	for (;t>0;t--){
		scanf("%llu", &n);
		w = 0;
		
		s = n, i = 0;
		while (s!=0){
			str[i++] = s%2;
			s = s/2;
		}

		sstrrev(str, i);
		c = i;

		i = 0, op = -1, obc = 0;
		for (i=c-1; i>=0; i--){
			if (op>-1) // 1s before last 1
			{
				if (str[i] == 1)
					obc++;
			}
			else if (str[i] == 1) // last 1 in bin - not go here if op fixed
				op = i;
		}
		
		w = ( obc + (c-op-1) ) % 2;

		printf("%s\n", w ? "Louise" : "Richard");

	}
	return 0;
}
