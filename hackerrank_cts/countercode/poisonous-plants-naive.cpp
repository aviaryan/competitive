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

// Brute Force Wins

int main(){
	int t, i, n, j;
	ios_base::sync_with_stdio(0);
	cin >> n;
	vector <int> arr;
	vector <int>::iterator vi2;
	int d, pre, pre2, dels, ind, lastdel;

	for (i=0; i<n; i++){
		cin >> j;
		arr.push_back(j);
	}

	lastdel = n;
	for (i=1; i<=n; i++){
		pre = MODULO; // more than ques
		d = 0;
		dels = 0;
		ind = 0;
		for (vector<int>::iterator vi = arr.begin(); vi != arr.end(); vi++){
			pre2 = *vi;
			ind++;
			if (*vi > pre){
				vi2 = vi;
				arr.erase(vi);
				vi2--;
				vi = vi2;

				d = ind; dels++;
			}
			pre = pre2;
			if (ind > lastdel) break;
		}
		lastdel = d - dels;
		if (!d)
			break;
	}

	cout << i-1;
	return 0;
}