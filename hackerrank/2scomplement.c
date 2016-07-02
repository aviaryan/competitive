#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*
For nth bit series
nums = pow(2,n-1)
total ones = nums * 0.5 * n + 0.5
*/

int countone(long long n){
    int count = 0;
    while (n > 0){
        count++;
        n = n & (n-1);
    }
    return count;
}

long long bunchcountone(long long a, long long b, int inv){
    long long num=1, s=0;
    for (num = a; num <=b; num++){
        s += countone(num);
    }
    if (inv==1)
        s = 32*(b-a+1) - s;
    return s;
}

int main() {

	int t;
    scanf("%d", &t);

    int i;
    long long n1,n2,s;

    for (i=0; i<t; i++){
    	scanf("%lld %lld", &n1, &n2);
        if ( (n1 < 0) && (n2 >=0) ){
            s = bunchcountone(0, -1*n1 - 1, 1) + bunchcountone(0, n2, 0);
        } 
        else if ( n2<0 ){
            s = bunchcountone(-1*n2-1, -1*n1-1, 1);
        }
        else {
            s = bunchcountone(n1, n2, 0);
        }
    	
        printf("%lld\n", s);
    }

    return 0;
}
