#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ifstream fin("A-large.in");
ofstream fout("output.txt");

int main(){
	int t, i, j, prev, n, rate, ans1, ans2;
	//ios_base::sync_with_stdio(0);
	fin >> t;
	int arr[1000];
	for (j=1; j<=t; j++){

		fin >> n;
		for (i=0; i<n; i++)
			fin >> arr[i];
		// first
		prev = arr[0]; ans1 = 0;
		for (i=1; i<n; i++){
			if (prev>arr[i])
				ans1 += (prev-arr[i]);
			prev = arr[i];
		}
		// second rate
		rate = 0;
		for (i=1; i<n; i++)
			rate = max(rate, arr[i-1]-arr[i]);
		ans2 = 0;
		for (i=0; i<(n-1); i++){
			if (arr[i] > rate)
				ans2 += rate;
			else
				ans2 += arr[i];
		}

		fout << "Case #" << j << ": " << ans1 << " " << ans2 << endl;
	}

	return 0;
}