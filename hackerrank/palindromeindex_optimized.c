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
	char s3[100006];
	char *ptr;

	for (;t>0;t--){
		scanf("%s", str);

		len = strlen(str);
		strcpy(sout, str);
		sstrrev(sout);

		if (strcmp(str, sout) == 0){
			printf("-1\n");
			continue;
		}

		for (i=0; i<len/2; i++){

			if (str[i] != str[len-i-1]){ // point found

				strcpy(s2, str);
				memmove(&s2[i], &s2[i + 1], strlen(s2) - i);
	
				strcpy(s3, sout);
				memmove(&s3[len-i-1], &s3[len-i], strlen(s3) - (len-i-1)); 	//memset(sout,0,strlen(sout));
	
				if (strcmp(s3, s2) == 0){
					printf("%d\n", i);
					break;
				}

				strcpy(s2, str);
				memmove(&s2[len-i-1], &s2[len-i], strlen(s2) - (len-i-1));
	
				strcpy(s3, sout);
				memmove(&s3[i], &s3[i + 1], strlen(s3) - i); 	//memset(sout,0,strlen(sout));
	
				if (strcmp(s3, s2) == 0){
					printf("%d\n", len-i-1);
					break;
				}

			}

		}

	}
}
