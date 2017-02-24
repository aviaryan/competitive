#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin >> t;
    int n,k,i,j;

    for (i=0; i<t; i++){
    	cin >> n >> k;
    	// k is number whose index is determined
    	// 12345 - 51423
    	j = n/2;
    	if (k>=j)
    		cout << (n-1-k)*2 << endl;
    	else
    		cout << 1+k*2 << endl;
    }
    return 0;
}
