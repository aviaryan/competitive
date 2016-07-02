#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"
#include "stdbool.h"

#define ull unsigned long long
#define ll long long
#define min(a,b) (a>b) ? b : a
#define max(a,b) (a>b) ? a : b

int IsPrime_temp(int n){
	 if (n < 2)
        return 0;
    else if (n < 4)
        return 1;
    else if (n % 2 == 0)
        return 0;
    else if (n < 9)
        return 1;
    else
    	return 0;
}

int IsPrimeZ(int n) {
	int f, r;
    if (n < 9)
        return 1;
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

int main(){
	int t;
	scanf("%d", &t);
	int a,b,gl, i, modestart, ans;

	while (t--){
		scanf("%d %d", &a, &b);
		modestart = 0, ans = 0;
		for (i=a; i<=b; i++){
			if ((i-5) % 6 == 0){
				modestart = 1;
				break;
			}
			if (IsPrime_temp(i)) printf("%d\n", i);
		}

		if (modestart==1){
			while (i<=b){
				if (IsPrimeZ(i)) printf("%d\n", i);
				if (i+2 > b) break;
				if (IsPrimeZ(i+2)) printf("%d\n", i+2);
				i+=6;
			}
		}

		printf("\n");
	}
	return 0;
}