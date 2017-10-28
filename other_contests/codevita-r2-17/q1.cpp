// decreasing digits

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



void solve(string s){
    ull m = s.size();
    ull a[m];
    for (ull i=0; i<m; i++)
        a[i] = s[i] - '0';
    ull level = m-1;
    for (ull i=m-1; i>0; i--){
        if (a[i] < a[i-1]){
            a[i-1]--;
            level=i-1;
        }
    }
 
    if (a[0] != 0){
        for (ull i=0; i<=level; i++)
            cout << a[i];
        for (ull i=level+1; i<m; i++)
            cout << "9";
    } else {
        for (ull i=1; i<level; i++)
            cout << a[i];
        for (ull i=level+1; i<m; i++)
            cout << "9";
    }
}


int main(){
	string str;
	cin >> str;
	solve(str);
    cout << endl;
	return 0;
}
