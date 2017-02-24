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

ll bigXor(ll a, ll b){
	ll mask = 1, p1, p2, sum = 0;
	for (int i = 0; i < 64; i++){
		p1 = mask & a;
		p2 = mask & b;
		if ((p1 == 0 && p2 != 0) || (p1 != 0 && p2 == 0))
			sum += pow(2,i);
		mask <<= 1;
	}
	return sum;
}

int main(){
	ull a, b;
	ios_base::sync_with_stdio(0);
	cin >> a >> b;
	cout << bigXor(a, b);
	 // testing


	return 0;
}