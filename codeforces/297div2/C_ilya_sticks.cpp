#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<int>::reverse_iterator viit;

int main(){
	int t, i, in;
	cin >> t;
	vi arr, done;
	ull ans=0;

	for (i=0; i<t; i++){
		cin >> in;
		arr.push_back(in);
	}

	sort(arr.begin(), arr.end());
	viit it;
	int lst=0, lst2=0;

	for (it = arr.rbegin(); it != arr.rend(); ++it){
		if (lst==0)
			lst = *it;
		else {
			if ((lst - *it) <= 1){
				if (lst2 == 0)
					lst2 = *it;
				else
					ans = ans + ((ull) lst2 * (*it)), lst2 = 0;
				lst = 0;
			} else
				lst = *it;
		}
	}

	cout << ans;

	return 0;
}