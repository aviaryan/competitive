#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int main(){
	int t, i, ml, wl;
	scanf("%d", &t);
	char m[50001], w[50001], s;
	int alphs[26];

	for (;t>0;t--){
		scanf("%s %s", m, w);
		s = 1;
		for (i=0; i<26; i++)
			alphs[i] = 0;
		ml = strlen(m), wl = strlen(w);

		if (ml != wl){
			printf("NO\n");
			continue;
		}

		for (i=0; i<ml; i++)
			alphs[ (int) m[i]-97 ]++, alphs[ (int) w[i]-97 ]--;
		// check
		for (i=0; i<26; i++)
			if ( alphs[i] != 0 ){
				s = 0;
				break;
			}

		if (s==1)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}