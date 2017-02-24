#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t;
    scanf("%d", &t);
    unsigned n;
    unsigned a = ~(1 << 32);

    for (;t>0;t--){
    	scanf("%u", &n);
    	printf("%u\n", n^a);
    }
    return 0;
}
