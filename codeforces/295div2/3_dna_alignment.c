#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int countCircularR(char * s, int len){
	char z1[len+1], z2[len+1];
	strcpy(z1, s);
	strcpy(z2, s);
	char t;

	int ans=1, i;

	for (i=0; i<(len-1); i++){
		t = z1[0];
		memmove(&z1[0], &z1[0 + 1], strlen(z1) - 0);
		z1[len-1] = t;
		z1[len] = '\0';
		//printf("A%s\n", z1);
		if (strcmp(z1, z2) == 0)
			break;
		else
			ans++;
	}
	return ans;
}

int main(){
	int t;
	scanf("%d", &t);
	char str[t+1];

	int cts[4] = {0}; //atgc
	scanf("%s", str);

	int i;
	for (i=0; i<t; i++){
		if (str[i] == 'A')
			cts[0]++;
		else if (str[i] == 'T')
			cts[1]++;
		else if (str[i] == 'G')
			cts[2]++;
		else if (str[i] == 'C')
			cts[3]++;
	}

	int mx=0;
	if (cts[0] > mx)
		mx = cts[0];
	if (cts[1] > mx)
		mx = cts[1];
	if (cts[2] > mx)
		mx = cts[2];
	if (cts[3] > mx)
		mx = cts[3];

	long mxvs = mx*t*t; // max = t^3 = when mx=t
	long genmx = cts[0]*t*cts[0] + cts[1]*t*cts[1] + cts[2]*t*cts[2] + cts[3]*t*cts[3];

	if (mx==1){
		//int cycs = countCircularR(str, t);
		// only 4 max
		int cycs = t;  // cycs
		if (t!=1)
			cycs += t; // singulars AA TT
		printf("%d\n", cycs);
	} else {
		int zc = (cts[0] == mx) + (cts[1] == mx) + (cts[2] == mx) + (cts[3] == mx);
		if (genmx == mxvs && zc > 1){
			zc += countCircularR(str, t);
		}
		printf("%d\n", zc);
	}

	return 0;
}