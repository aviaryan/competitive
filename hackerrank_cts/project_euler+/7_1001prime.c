#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define LS 10000

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
	int t, ct=1, n,b;
	scanf("%d", &t);
	b = t;
	unsigned long long arr[LS], f;

	arr[0] = 2, arr[1] = 3;
	for (f=5; ct<LS; f+=6){
		if ( IsPrime(f) == 1 )
			arr[++ct] = f;
		if ( IsPrime(f+2) == 1 )
			arr[++ct] = f+2;
	}

	for (;t>0;t--){
		scanf("%d", &n);
		printf("%llu\n", arr[n-1]);
	}
    return 0;
}
