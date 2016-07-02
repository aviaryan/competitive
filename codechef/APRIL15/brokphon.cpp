#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, n, j, ans=0, in, pre;
	cin >> t;
	while (t--){
		cin >> n >> j;
		ans = 0;
		pre = 0;
		n--;
		while (n--){
			scanf("%d", &in);
			if (in != j){
				ans += pre ? 1 : 2;
				pre = 1;
			} else
				pre = 0;
			j = in;
		}
		cout << ans << endl;
	}
	return 0;
}