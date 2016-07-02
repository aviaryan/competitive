#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int IsPrime(int n) {         //by kon
	int f, r;
    if (n < 2)
        return 0;
    else if (n < 4)
        return 1;
    else if (n % 2 == 0)
        return 0;
    else if (n < 9)
        return 1;
    else if (n % 3 == 0)
        return 0;
    else {
        r = floor(sqrt(n));
        f = 5;
        while (f <= r) {
            if (n % f == 0)
                return 0;
            if (n % (f + 2) == 0)
                return 0;
            f += 6;
        }
        return 1;
    }
}

int primefact(int n){
	int srt = floor( sqrt(n) );
	int i, ct=0;
	if (IsPrime(n) == 1)
		ct=1;

	for (i=2; i<=srt; i++){
		if (n%i == 0){
			if (IsPrime(i) == 1)
				ct++;
			if (IsPrime(n/i) == 1)
				if ((int) n/i != i)
					ct++;
		}
	}

	return ct;
}

int main(){
	int t;
	scanf("%d", &t);

	// pre-caching
	int n[100000], i, j;
	for (i=1;i<100000; i++){
		n[i] = primefact(i+1);
	}

	int x,y,k, one, two, ct;
	for (;t>0;t--){
		scanf("%d %d %d", &x, &y, &k);
		one = x-1;
		two = y+1;
		ct = 0;
		while (two>one){

			ct += 2;
			for (j=(one+1); j<=y; j++){
				one = j;
				if ( n[j-1] == k )
					break;
			}
			for (j=(two-1); j>=x; j--){
				two = j;
				if ( n[j-1] == k )
					break;
			}

		}
		printf("%d\n", ct-2);
	}

	return 0;
}