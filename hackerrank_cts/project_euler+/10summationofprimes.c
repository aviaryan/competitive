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
	unsigned long long t,n,pp;
	scanf("%llu", &t);
	unsigned long long sum;
	int arr[400000] = {0}, ict=0, i; // most prob primes under 10^6 is 10^6/3

	for (n=2; n<=1000000; n++){
		if (IsPrime(n))
			arr[ ict++ ] = n;
	}

	for (;t>0;t--){
		scanf("%llu", &n);
		sum = 0;
		for (i=0; i<ict; i++){
			if (arr[i] > n)
				break;
			sum += arr[i];
		}
		printf("%llu\n", sum);
	}
}
