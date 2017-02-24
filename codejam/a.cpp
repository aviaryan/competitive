#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

//ifstream fin("A-small-attempt3.in");
ifstream fin("input.in");
ofstream fout("output.txt");

ll reversen(ll n){
	ll s=0, r;
	while (n){
		r = n%10;
		s = s*10 + r;
		n = n/10;
	}
	return s;
}

int main(){
	int t, i;
	//ios_base::sync_with_stdio(0);
	fin >> t;
	ll n,cc,bs,st,k,temp,temp2,j;
	ll st1, st2;

	for(j=1; j<=t; j++){
		fin >> n;
		if (n<=10){
			fout << "Case #" << j << ": " << n << endl;
			continue;
		}
		cc = (log(n)/log(10)) + 1;
		st = 10;
		k = 2;
		while (k<cc){
			st += ( pow(10,k-1) + 9 );
			k++;
		}
		bs = pow(10,k-1);

		if (n==bs){
			fout << "Case #" << j << ": " << st << endl;
			continue;
		}

		// make 1 in n
		st1 = 0;
		temp = n%10;
		if (temp == 0){
			temp = (n/10 - 1) * 10 + 1;
			st1 += (n-temp);
		}
		else if (temp != 1){
			temp = (n/10)*10 + 1;
			st1 += (n-temp);
		} else {
			temp = n;
		}
		temp2 = reversen(temp);
		temp2 = min(temp2, temp);
		if (temp2 != temp)
			st1++;

		// make x in 1000..
		temp = n / ((ll)pow(10,k-1));
		st2 = temp;
		if (temp != 1) // 1203
			st2++;
		temp = (temp * pow(10,k-1)) + 1; // 9001
		if (n<temp) // 9000
			st += ( st1+(temp2-bs) );
		else
			st += min( st1+(temp2-bs) , st2+(n-temp) );


		fout << "Case #" << j << ": " << st << endl;
	}

	return 0;
}