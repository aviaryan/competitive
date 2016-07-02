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

//ifstream fin("input.txt");
ifstream fin("A-large.in");
ofstream fout("output.txt");


bool digits[10];
int ct;

void rDigits(ll n){
	ll r = n%10;
	if (n==0){
		if (digits[0] == false){
			digits[0] = true;
			ct++;
		}
	}

	while (n > 0){
		if (digits[r] == false){
			digits[r] = true;
			ct++;
		}
		n /= 10;
		r = n % 10;
	}
}

int main(){
	int t, i, j;
	fin >> t;
	ll n, n2;

	for (j=1; j<=t; j++){
		fin >> n;
		for (i=0; i<10; i++){
			digits[i] = false;
		}
		ct = 0;

		rDigits(n);
		n2 = n;
		if (n2 != 0){
			for (i=0; i<10000000; i++){
				rDigits(n2 = n2+n);
				if (ct == 10) break;
			}
		}

		fout << "Case #" << j << ": ";
		if (ct == 10){
			fout << n2 << endl;
		} else {
			fout << "INSOMNIA" << endl;
		}
	}

	return 0;
}