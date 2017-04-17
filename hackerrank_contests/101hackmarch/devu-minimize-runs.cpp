#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;

int main(){
	int t, slen, lc, bk, onep, i, onep2;
	cin >> t;
	char str[2000000];
	vi ss;
	char lst;

	while (t--){
		scanf("%s", str);		
		slen = strlen(str);
		ss.clear();
		lst = str[0];
		lc = 1, onep=0, onep2 = 0;
		for (i=1; i<=slen; i++) // =slen done intentionally to put the last series in as compared with \0
			if (str[i] != lst){
				ss.push_back(lc);
				if (lc == 1){
					onep2 = onep;
					onep = ss.size();
				}
				lst = str[i];
				lc = 1;
			} else
				lc++;

		bk = ss.size();
		if (bk < 3)
			printf("%d\n", bk);
		else if (bk == 3)
			printf("%d\n", onep>0 ? bk-1 : bk); // wheerever one no matter same result
		else {
			if (onep == bk)
				printf("%d\n", onep2>1 ? bk-2 : bk-1);
			else if (onep == 1)
				printf("%d\n", bk-1);
			else if (onep == 0)
				printf("%d\n", bk);
			else
				printf("%d\n", bk-2);
		}

	}

	return 0;
}