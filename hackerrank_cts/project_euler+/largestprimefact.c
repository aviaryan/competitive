#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int IsPrime(unsigned long long n) {         //by kon
	unsigned long long f, r;
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

int main() {
	int t;
	scanf("%d", &t);
	unsigned long long n,f,i, compi, hpf ;
	for (;t>0;t--){
		scanf("%llu", &n);
		f = floor( sqrt(n) )+1;
		for (i=1; i<=f; i++){
			if (n%i == 0){
				compi = n/i;
				if ( IsPrime(compi) == 1 ){
					hpf = compi;
					break;
				} else
					if ( IsPrime(i) == 1 )
						hpf = i;
			}
		}

		printf("%llu\n", hpf);
	}   
    return 0;
}
