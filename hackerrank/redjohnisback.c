#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int IsPrime(long long n) {         //by kon
    if (n < 2)
        return 0;
    else if (n < 4)
        return 1;
    else if ((n % 2) == 0)
        return 0;
    else if (n < 9)
        return 1;
    else if ((n % 3) == 0)
        return 0;
    else {
        long long r = sqrt(n)+1;
        long long f = 5;
        while (f <= r) {
            if ((n % f) == 0)
                return 0;
            if ((n % (f + 2)) == 0)
                return 0;
            f += 6;
        }
        return 1;
    }
}

long long fact(int n){
	return (n<2) ? 1 : n*fact(n-1);
}

long long factdiv(int a, int b){  // a!/b!
	if (b>a)
		return 0;
	if (b==0)
		b = 1;
	int i;
	i = a-b;
	unsigned long long z=1;
	for (i=b+1; i<=a; i++){
		z *= i;
	}
	return z;
}

int main() {
	int k;
	scanf("%d", &k);

	int i,n,j,m;
	unsigned long long w=0, temp, pc=0;
	for (i=0; i<k; i++){
		scanf("%d", &n);
		w = 0;
		pc = 0;
		j = n/4;

		for (m=0; m<=j; m++){
			temp = factdiv(n-m*3, n-m*4);
			w += temp/fact(m);
		}

		for (temp=2; temp<=w; temp++){
			if (IsPrime(temp) == 1)
				pc++;
		}
		printf("%llu\n", pc);
	}
	return 0;
}
