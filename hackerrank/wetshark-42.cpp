#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t;
	cin >> t;
	ull s;
	while (t--){
		scanf("%llu", &s);
		printf("%llu\n", ( (s + (s/20) + (s%20==0 ? -1 : 0) )*2 ) % MODULO);
	}
	return 0;
}