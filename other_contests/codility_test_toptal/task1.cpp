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


int solution(vector<int> &T) {
    // write your code in C++14 (g++ 6.2.0)
    int n = T.size(), i;
    int arr[n], maxfw[n], minbk[n], ind = 0;
    vector<int>::iterator vit;
    // load data into array for easy processing
    for (vit = T.begin(); vit != T.end(); vit++){
        arr[ind++] = *vit;
    }
    // get fwd max
    maxfw[0] = arr[0];
    for (i=1; i<n; i++){
        maxfw[i] = max(arr[i], maxfw[i-1]);
    }
    // get min back
    minbk[n-1] = arr[n-1];
    for (i=n-2; i>=0; i--){
        minbk[i] = min(arr[i], minbk[i+1]);
    }
    // start from start
    for (i=0; i<(n-1); i++){
        if (maxfw[i] < minbk[i+1])
            return i+1;
    }
    return n;
}


int main(){
	int t, i;
	vector<int> v;
	v.push_back(-5);
	v.push_back(-5);
	v.push_back(-42);
    v.push_back(6);
    v.push_back(12);
	cout << solution(v) << endl;
	return 0;
}
