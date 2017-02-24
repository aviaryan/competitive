#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isfib(unsigned long long n){

    if (n<2)
        return 1;

    unsigned long long i=1, fib=1, j;

    for (;;) {
        j = i;
        i = fib;
        fib += j;
        if (fib==n)
            return 1;
        else if (fib>n)
            return 0;
    }

}


int main() {

    int k;
    scanf("%d", &k);

    int i;
    unsigned long long n;
    for (i=0; i<k; i++){
        scanf("%llu", &n);
        printf("%s\n", (isfib(n)==1) ? "IsFibo" : "IsNotFibo");
    }
    
}