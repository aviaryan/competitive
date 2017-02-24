#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int i, j, n, res=0;
	scanf("%d", &n);
	char str[101];
	char arr[26] = {0};
	char chr;

	for (i=0; i<n; i++){

		scanf("%s", str); // get string
		chr = 'a';

		for (j=0; j<26; j++){
			if ( strchr(str, chr) != NULL )
				arr[j]++;
			chr++;
		}

		// empty str
		str[0] = '\0';
	}

	// declare
	for (i=0; i<26; i++){
		if (arr[i] == n)
			res++;
	}
	printf("%d", res);

    return 0;
}
