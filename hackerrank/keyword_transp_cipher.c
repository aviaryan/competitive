#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
	int t, i, j, l, k, colnum, ct, temp_rowc;
	scanf("%d", &t);

	char keyword[8], msg[256], c;
	int cols[8][26], rowc;
	int ocd[26], replacmnt[26];

	for (;t>0;t--){
		scanf("%s", keyword);

		// clean old ocd
		for (i=0;i<26;i++)
			ocd[i] = 0;

		// remove dups in keyword
		l = strlen( keyword );
		for (i=0; i<l; i++){
			k = (int) keyword[i] - 65;
			if ( ocd[k] == 0 ){
				ocd[k] = 1;
			} else {
				memmove(&keyword[i], &keyword[i + 1], strlen(keyword) - i); 
				l--;
				i--;
			}
		}

		// add to cols
		colnum = 0; rowc = 0;
		for (i=0; i<26; i++){
			if ( ocd[ i ] == 0 ){
				cols[ colnum ][ rowc ] = i;
				colnum++;
				if (colnum == l){
					colnum = 0;
					rowc++;
				}
			}
		}

		// make real rows and columns
		if (colnum==0){
			rowc--;
			colnum=l-1;
		}
		else
			colnum--;


		// build replacements
		ct = 0;
		for (i=0; i<26; i++){
			if ( ocd[i] == 1 ){ // in alphabetical order by default
				// find that character
				for (j=0; j<l; j++){
					if ( keyword[j] == (char) i+65 )
						break;
				}
				// working a/c that
				temp_rowc = rowc-1;
				if (j <= colnum)
					temp_rowc++;

				//printf("_%d_%d_", j, temp_rowc);

				// the final step of building replacements - as encoded is back to decoded , so oppsoite of replacement is used
				replacmnt[ i ] = ct++;
				for (k=0; k<=temp_rowc; k++)
					replacmnt[ cols[j][k] ] = ct++;
			}
		}

		// get string and replace
		c = getchar();
		scanf("%[^\n]s", msg);
		for (i=0; i<strlen(msg); i++){
			printf("%c", msg[i] == ' ' ? ' ' : (char) replacmnt[ (int) msg[i] - 65 ] + 65  );
		}
		if (t>1)
			printf("\n");

	} 

    return 0;
}