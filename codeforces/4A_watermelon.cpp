#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t;
	cin >> t;
	printf("%s\n", t%2 == 0 && t>2 ? "YES" : "NO");
	return 0;
}