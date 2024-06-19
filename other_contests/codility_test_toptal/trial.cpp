// you can use includes, for example:
// #include <algorithm>

#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%d\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int>::iterator vit;
    sort(A.begin(), A.end());
    int ct = 1;
    for (vit = A.begin(); vit != A.end(); vit++){
    	if (*vit > 0) {
    		if (*vit < ct) {
    			continue; // ok
    		}
    		if (*vit != ct) {
    			return ct;
    		} else {
    			ct++;
    		}
    	}
    }
    return ct;
}


int main(){
	int t, i;
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	cout << solution(v) << endl;
	return 0;
}
