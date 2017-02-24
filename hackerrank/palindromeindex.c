#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sstrrev(char *s){
	int k;
	k = strlen(s);
	int i;
	char c;
	for (i=0; i<k/2; i++){
		c = s[i];
		s[i] = s[k-i-1];
		s[k-i-1] = c;
	}
}

int main() {
	int t,i, len;
	scanf("%d", &t);
	char str[100006]; //[100006];
	char sout[100006];
	char s2[100006];
	char *s3;
	char *ptr;

	for (;t>0;t--){
		scanf("%s", str);

		len = strlen(str);
		strcpy(s2, str);
		sstrrev(s2);

		if (strcmp(str, s2) == 0){
			printf("-1\n");
			continue;
		}

		for (i=0; i<len; i++){

			memset(sout,0,strlen(sout));

			strncpy(sout, str, i);

			if (i != len-1){
				ptr = &str[i+1];
				strcat(sout, ptr);
			}

			strcpy(s2, sout);
			sstrrev(s2);

			if (strcmp(sout, s2) == 0){
				printf("%d\n", i);
				break;
			}
		}

	}
}
