#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	char str[1200000], tstr[600000];
	int sz[300000]; // pehle se record
	char zero[2];
	zero[0] = '|', zero[1] = '\0';

	int i,j,k,in;
	for (i=0; i<n; i++){
		scanf("%s", tstr);
		strcat(str, tstr);
		strcat(str, zero);
		sz[i] = strlen(tstr); // use this for better results
	}

	int slen = strlen(str), tlen;
	int success=0, diff;

	for (in=0; in<m; in++){
		scanf("%s", tstr);
		success = 0;

		tlen = strlen(tstr);
		for (i=0; i<slen; i++){

			j = i;
			while (str[j] != '|')
				j++;
			if ( tlen == (j-i) ){ // same len
				diff = 0;
				for (k=i; k<(i+tlen); k++){
					if (str[k] != tstr[k-i])
						diff++;
					if (diff>1)
						break;
				}
				//printf("%d", diff);
				if (diff == 1){
					printf("YES\n");
					success = 1;
					break;
				}
			}
			i = j;
		}

		if (success == 0)
			printf("NO\n");
	}

	return 0;
}