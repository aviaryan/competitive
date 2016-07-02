#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int t, n, c, m;
    scanf("%d", &t);
    int max, rapprem;
    int answer;
    while ( t-- )
    {
        scanf("%d%d%d",&n,&c,&m);
        answer = 0; 
        /** Write the code to compute the answer here. **/
        
        max = n/c;
        answer += max;
        rapprem = max;

        while (rapprem >= m){
            max = rapprem/m; // how much buy
            rapprem = rapprem - max*m; // left
            answer += max; // more buy
            rapprem = rapprem + max; // inc from buy
        }

        printf("%d\n",answer);
    }
    return 0;
}
