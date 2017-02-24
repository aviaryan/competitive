#include <stdio.h>
#include <math.h>

void dec2bin(unsigned dec, int *str, int len){
	int i=0,j,t;

	for (j=0; j<len; j++)
		str[j] = 0;

	while (dec!=0){ 
		str[i++] = dec%2;
		dec = dec/2;
	}

	for (j=0; j<(len/2); j++){ 	// reverse
		t = str[j];
		str[j] = str[len-1-j];
		str[len-1-j] = t;
	}
}

void dec2gray(unsigned dec, int *str, int len){
	int s2[len];
	dec2bin(dec, s2, len);
	int i, p = 0;

	for (i=0; i<len; i++){
		str[i] = p^s2[i];
		p = s2[i];
	}
}

unsigned bin2dec(int *str, int len){
	int i=0;
	unsigned res=0;

	for (i=0; i<len; i++){
		res = res + pow(2,len-i-1)*str[i];
	}
	return res;
}

unsigned graydec2dec(unsigned num){
	unsigned mask;
	for (mask = num >> 1; mask != 0; mask = mask >> 1)
	    num = num ^ mask;
	return num;
}

unsigned dec2graydec(unsigned num){
       return (num >> 1) ^ num;
}


main(){
	int k,t,i,j;
	printf("Enter number of variables\n");
	scanf("%d", &k);
	int arr[ (int) pow(2,k) ], arrlen;
	printf("\n#################\nEnter minterms one by one. Enter -1 when done\n");

	i = 0;
	scanf("%d", &t);
	while (t>=0){
		arr[ i++ ] = t;
		scanf("%d", &t);
	}
	arrlen = i;

	int r,c;
	r = 2 * ((int) k/2);
	c = r + 2*(k%2);

	int mx[r][c];

	for (i=0; i<r; i++) // 0 all
		for (j=0; j<c; j++)
			mx[i][j] = 0;

	int sbin[k], sgray[k], stemp[k], rgray, cgray;
	t = k/2;
	// fill mx
	for (i=0; i<arrlen; i++){
		dec2bin(arr[i], sbin, k);
		rgray = bin2dec(&sbin[0], t);
		cgray = dec2graydec( bin2dec(&sbin[t], k-t) ); // arranged a/c gray dec
		mx[ rgray ][ cgray ] = 1;
	}

	// extract
	// use farmer's code

	int i0;
	// something like 4x1 is also possbile in 3 var kmap. so vary
	for (i0=0; i0<=k; i0++){
		i = 2*(t-i0);
		j = 2*((t-i0) + (k-i0+1)%2); 
		i = i==0 ? 1 : i;
		j = j==0 ? 1 : j;

		printf("#%d-%d#", i, j);
		/*// got dimensions - now scan
			ct = 0;

			for (i2=0; i2<n-i; i2++){
				for (j2=0; j2<m-j; j2++){
				// got init point to scan (leftmost) - now large

					for (i3=i2; i3<=i2+i; i3++)
						for (j3=j2; j3<=j2+j; j3++)
							if ( arr[i3][j3] == '0' ){
								ct--; //optimize
								break;
							}
					ct++;
				// end scan
				}
			}

		// end of one dimension*/
	}

}