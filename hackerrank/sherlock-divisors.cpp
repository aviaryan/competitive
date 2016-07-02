#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t,n, srt, ns, i, ct;
    cin >> t;

    for (;t>0;t--){
    	cin >> n;

    	if (n%2 != 0){
    		cout << 0 << endl;
    		continue;
    	}

    	srt = sqrt(n);
    	ns = (srt*srt == n && srt%2==0) ? 1 : 0;
    	ct = 0;
    	for (i=1; i<=srt; i++){
    		if (n%i == 0){
    			if (i%2 == 0)
    				ct++;
    			if ( ((int) n/i)%2 == 0 )
    				ct++;
    		}
    	}
    	cout << (ns==1 ? ct-1 : ct) << endl;
    }  

    return 0;
}
