#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	char str[82];
	scanf("%s", str);
	int sl = strlen( str );
	int ll = floor( sqrt(sl) ), ul = ceil( sqrt(sl) );
	int w,h,i,j,k,c;

	// h can never be more than w
	// so cases
	w = ll, h=ll;
	if (w*h < sl){
		w = ul;
		if (w*h < sl){
			h=ul;
		}
	}

	for (i=0; i<w; i++){ // width i.e cols
		k = i;
		for (j=0; j<h; j++){ // one row at a time
			c = k + j*w;
			if (c>=sl)
				break;
			printf("%c", str[c]);
		}
		printf(" ");
	}

	return 0;
}
