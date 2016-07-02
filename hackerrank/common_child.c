#include <stdio.h>
#include <string.h>

main(){
	char a[5001], b[5001];

	scanf("%s %s", a, b);
	char *aptr, *bptr, *bptrcpy;
	int car[26] = {0}, i, j, k, co, max=0, tmax=0, end;
	int ans=0;
	int al = strlen(a);
	int bl = strlen(b);
	a[al] = '\0';
	b[bl] = '\0';

	for (i=0; i<al; i++){
		aptr = &a[i];
		bptr = b;
		tmax = 0;

		while (aptr[0] != '\0'){

			end = 0;
			bptrcpy = bptr;
			while (bptr[0] != '\0' && end == 0){
				if ( aptr[0] == bptr[0] ){
					tmax++;
					end = 1;
				}
				bptr++;
				//break;
			}
			if (end != 1)
				bptr = bptrcpy;

			aptr++;
		}

		if (tmax > max)
			max = tmax;
	}

	printf("%d", max);

}