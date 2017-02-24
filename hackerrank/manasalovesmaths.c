#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define DIVDS 125

int main() {
	int t, i, len,j, tdivds;
	char str[112];
	int numarr[10], s, ps;
	scanf("%d", &t);

	// find all 000 numbers divisible by 8
	int divs[DIVDS][10], r, ibk;
	for (i=0; i<DIVDS; i++)
		for (j=0; j<10; j++)
			divs[i][j] = 0;

	for (i=0; i<=999; i+=8){
		ibk = i;
		divs[ i/8 ][0] = 3;
		while (ibk > 0){
			r = ibk%10;
			divs[ i/8 ][r]++;
			divs[ i/8 ][0]--;
			ibk = ibk/10;
		}
	}

	// the code
	for (;t>0;t--){
		scanf("%s", str);
		len = strlen(str);

		s = 0;
		for (j=0; j<10; j++)
			numarr[j] = 0;
		if (len<3)
			numarr[0] = 3-len;
		for (j=0; j<len; j++){
			numarr[ (int) str[j] - 48 ]++;
		}

		//printf("%d", numarr[2]);
		if (len<3)
			tdivds = 13; // less than 104 - 2 digit
		else
			tdivds = DIVDS;

		for (j=0; j<tdivds; j++){
			ps = 1;
			for (i=0; i<10; i++)
				if (numarr[i] < divs[j][i]){
					ps = 0; 
					break;
				}
			if (ps==1){
				s = 1; 
				break;
			}
		}

		printf("%s\n", s==1 ? "YES" : "NO");
	}  
    return 0;
}
