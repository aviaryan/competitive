#include <iostream>
#include <math.h>

using namespace std;

main(){
    int t;
    cin >> t;

    int n, i, sq, j;
    unsigned long long sum;

    for (i=0; i<t; i++){
        cin >> n;
        sum = 0;
        sq = ceil( sqrt(n) );

        if (n==1){
            cout << 0 << endl;
            continue;
        }
        for (j=1; j<=sq; j++){
            if (n%j == 0){
                sum += j;
                if ((n/j) > sq)
                    sum += (n/j);
            }
        }
        cout << sum-n << endl;
    }
}
