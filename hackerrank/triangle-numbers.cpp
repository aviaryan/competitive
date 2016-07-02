#include <bits/stdc++.h>

using namespace std;
#define MODULO 1000000007

typedef vector<int> vi;
typedef vector<int>::iterator vii;
typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, n;
	cin >> t;
	while (t--){
		scanf("%d", &n);
		n-=2;
		if (n%2 == 1)
			printf("2\n");
		else
			printf("%d\n", n%4==0 ? 4 : 3);
	}
	return 0;
}