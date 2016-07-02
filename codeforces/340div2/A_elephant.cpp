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


int main(){
	int n, i;
	ios_base::sync_with_stdio(0);
	cin >> n;

	int a = n / 5;
	if (n % 5 != 0)
		a++;
	cout << a << endl;


	return 0;
}