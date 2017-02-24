#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i;
	cin >> t;
	double reg=0, in;
	for (i=0; i<t; i++){
		cin >> in;
		reg += in;
	}

	printf("%.5f", reg/t);
	return 0;
}