#include "bits/stdc++.h"
using namespace std;
#define MODULO 1000000007

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, slen, suc, i;
	cin >> t;
	string s1, s2;
	while (t--){
		int arr[150] = {0};
		cin >> s1 >> s2;
		suc = 0;
		slen = s1.size();
		for (i=0; i<slen; i++)
			arr[s1[i]] = 1;
		slen = s2.size();
		for (i=0; i<slen; i++)
			if (arr[s2[i]]){
				suc = 1;
				break;
			}
		printf("%s\n", suc==1 ? "YES" : "NO");
	}
	return 0;
}