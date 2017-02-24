#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
typedef vector<int> vi;
typedef vector<int>::iterator vii;
typedef unsigned long long ull;
typedef long long ll;

#define MODULO 1000000007


ll PowMod(int bs, int n, int modx)
{ // base^n % modx
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % modx;
        a = a * a % modx;
        n >>= 1;
    }
    return ret;
}

// Can use Euler criteria too
int modular_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

int main(){
	int t;
	cin >> t;
	ll a,b,x;

	while (t--){
		cin >> a >> b >> x;
		if (b<0){
			printf("%lld\n", PowMod(mul_inv(a, x), -b, x) );
		}
		else
			printf("%lld\n", PowMod(a,b,x));
	}

	return 0;
}