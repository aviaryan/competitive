#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
   	int t;
   	cin >> t;
   	unsigned long long n, crt, j, n6;

   	for (;t>0;t--){
   		cin >> n;
   		crt = pow(n6 = n*6, 1/3.);
   		for (j=crt; j>0; j--){
   			if ( j*(j+1)*(2*j+1) <= n6 )
   				break;
   		}
   		cout << j << endl;
   	}

    return 0;
}
