#include <bits/stdc++.h>

using namespace std;
#define MODULO 100

typedef vector<int> vi;
typedef vector<int>::iterator vii;
typedef unsigned long long ull;
typedef long long ll;


ull PowMod(ull bs, ull n)
{ // base^n % modx
    ull ret = 1;
    ull a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % 100;
        a = a * a % 100;
        n >>= 1;
    }
    return ret;
}

int main(){
	int t, i;
	cin >> t;
	ull n, k, mod100, divs, rems, ans;

	while (t--){
		scanf("%llu %llu", &n, &k);
		mod100 = 0;
		for (i=1; i<100; i++)
			mod100 += PowMod(i,k);
		mod100 %= 100;
		divs = n/100;
		rems = n%100;
		ans = 0;
		ans = (divs % 100) * mod100;
		ans %= 100;
		for (i=1; i<=rems; i++)
			ans += PowMod(i, k);
		ans %= 100;
		printf("%02llu\n", ans);
	}
	return 0;
}