#include "bits/stdc++.h"
using namespace std;

int main(){
	int c, r;
	long long ans;
	cin >> r >> c;
	ans = (r+1)/2;
	ans = (ans-1)*10;
	printf("%lld\n", ans -2 + 2*c + (r%2==0 ? 1 : 0) ); 
	return 0; 
}