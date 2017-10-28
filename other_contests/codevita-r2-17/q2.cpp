// hostel owner

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
	int t, i, n, rc, j;
	cin >> n;
	string s[n];
	for (i=0; i<n; i++){
		cin >> s[i];
		// cout << "dd" << s[i] << endl;
	}
	cin >> rc;
	// cout << s[0];
	int cst = 0, num;
	for (i=0; i<n; i++){
		num = 0;
		// normal conversion
		for (j=0; j<6; j++){
			s[i][j] = s[i][j] - 17;
		}
		// cout << "dd" << s[i] << endl;
		// special replace
		for (j=1; j<6; j++){
			if (s[i][j-1] <= s[i][j]) continue; // AJ - pass
			if (s[i][j-1] + s[i][j] == (96+9)){
				s[i][j-1] = s[i][j];
			}
		}
		// make number
		for (j=0; j<6; j++){
			num = 10 * num + (s[i][j]-48);
		}
		// cout << "dd" << num << endl;
		cst += num;
	}

	// cout << s[0];
	if (cst <= rc){
		cout << "INNOCENT" << endl;
	} else {
		cout << "GREEDY" << endl << (cst-rc) << endl;
	}

	return 0;
}
