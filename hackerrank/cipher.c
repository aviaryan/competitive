#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char str[2000001];
	char sout[1000001];
	unsigned long n,k,slen,i,j,min;
	int prev=0, chk=0;
	scanf("%lu %lu", &n, &k);
	scanf("%s", str);
	slen = n+k-1;

	min = (k<n) ? k : n;
	for (i=0; i<min; i++){
		prev = chk ^ ( (int) str[slen-i-1] - 48 );
		sout[i] = (char) prev+48;
		chk = chk ^ prev;
	}

	if (k<n){
		for (i=0; i<n-k; i++){
			prev = (int) str[slen-k-i-1] - 48;
			for (j=0; j<k-1; j++)
				prev = prev ^ ( ((int) sout[i+j+1]) - 48 );
			sout[min+i] = (char) prev+48;
		}
	}

	for (i=0; i<n; i++)
		printf("%c", sout[n-i-1]);

	return 0;
}