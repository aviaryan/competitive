#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ifstream fin("B-large.in");
ofstream fout("output.txt");

int main(){
	ll t, i, j, arr[1000], jmp, mid, secs, presec, n, b, mx, ans;
	//ios_base::sync_with_stdio(0);
	fin >> t;

	for (j=1; j<=t; j++){

		fin >> b >> n;
		mx = 0;
		for (i=0; i<b; i++){
			fin >> arr[i];
			mx = max(mx, arr[i]);
		}
		jmp = 0;
		for (i=0; i<b; i++)
			jmp += (mx/arr[i]);
		secs = ceil(n/(double) jmp) * mx; // will be more than reqd
		presec = 0;
		ans = -1;

		while (secs > presec){
			jmp = 0;
			mid = (secs+presec)/2;
			for (i=0; i<b; i++)
				jmp += (mid/arr[i]);
			if (jmp > n)
				secs = mid-1;
			else if (jmp < n)
				presec = mid+1;
			else {
				//cout << "ans " <<  mid << endl;
				ans = mid;
				break;
			}
		}

		if (ans == -1)
			ans = secs;
		//cout << "s" << ans << endl;
		jmp = 0;
		//v.clear();
		while (true){
			jmp=0;
			for (i=0; i<b; i++){
				jmp += ceil(ans/(double)arr[i]);
			}
			if (jmp<n)
				break;
			ans--;
		}

		for (i=0; i<b; i++){
			if (ans%arr[i] == 0){
				jmp++;
				if (jmp==n){
					fout << "Case #" << j << ": " << i+1 << endl;
					break;
				}
			}
		}
		
	}
	return 0;
}