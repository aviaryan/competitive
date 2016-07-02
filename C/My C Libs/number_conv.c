#include "stdio.h"
#include <strings.h>
#include <math.h>

void dec2bin(unsigned dec, char *str){
	unsigned mask = 1 << 31;
	int c, d=0, ind=0;
	for (c=1; c<=32; c++){
		if (d==0)
			if ( dec & mask )
				d = 1;
		if (d==1)
			str[ind++] = dec & mask ? '1' : '0';
		dec <<=1;
	}
	str[ind] = '\0';
}

void dec2bin2(unsigned long long dec, int *str){
	unsigned long long s = dec;
	int i,j,t;

	while (s!=0){ 
		str[i++] = s%2;
		s = s/2;
	}

	for (j=0; j<i/2; j++){ 	// reverse
		t = str[j];
		str[j] = str[i-1-j];
		str[i-1-j] = t;
	}
}

unsigned rad2dec(char *str, int base){
	int i=0,len=0;
	unsigned res=0, t;

	while (str[i] != '\0')
		i++;
	len = i;

	for (i=0; i<len; i++){
		t = (int) str[i];
		if (t>60)
			t = (int) str[i] - 55;
		else
			t = (int) str[i] - 48;
		res = res + pow(base,len-i-1)*t;
	}
	return res;
}


main(){
	char *str = "ABC";
	unsigned l;
	printf("%u\n", l = rad2dec(str, 16));
	char *sbin;
	dec2bin(l, sbin);
	puts(sbin);
}
