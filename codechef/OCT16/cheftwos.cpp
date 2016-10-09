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

char s1[100000 + 1], s2[100000 + 1];
int n;

// fast POW
ll PowMod(int bs, int num){
    ll ret = 1;
    ll a = bs;
    while (num > 0) {
        if (num & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        num >>= 1;
    }
    return ret;
}

int type(int l){ // make a define
	return (l>=n) ? 999 : ((int)s1[l] - 49) + ((int)s2[l] - 49);
}

// solve a segment. find if good
ll solveSeg(int l, int r){
	int i, j;
	if (l > r){
		return 1;
	} else if (l == r){ // 1 length
		return -1;
	} else if (l+1 == r){ // 2 length
		if ( (type(l) == 1 && type(r) == 1) || type(l)+type(r)==4 ){
			i = 0;  // pass
		} else {
			return -1;
		}
	} else { // 3 length
		for (i=l; i<=r; i++){
			if (type(i) == 1 && type(i+1) == 2){
				if (type(i+2) != 1)
					return -1;
				else
					i = i+2; // plused in loop
			} else if (type(i) == 1 && type(i+1) == 1){
				for (j=i+2; j<r; j+=2){
					if (!(type(j) == 1 && type(j+1) == 1))
						break;
				}
				i = j-1; // plused in loop
			} else {
				return -1;
			}
		}
	}
	// find ans
	int twocount = 0;
	for (i=l; i<=r; i++)
		if (type(i) == 2)
			twocount ++;
	if (twocount == r-l+1){
		return PowMod(2, twocount);
	} else {
		return m(PowMod(2, twocount) * 2LL);
	}
}

int main(){
	int t, i, j;
	s(t);
	int prev_x, one_c;
	ll ans, temp;

	while (t--){
		scanf("%s", s1);
		scanf("%s", s2);
		prev_x = -1;
		one_c = 0;
		ans = 1;
		n = strlen(s1);
		// special case for algo
		if (n == 1){
			printf("2\n");
			continue;
		}
		for (i=0; i<n; i++){
			for (j=i; j<n; j++){
				if (s1[j] == '1' && s2[j] == '1'){
					one_c++;
					temp = solveSeg(prev_x+1, j-1);
					if (temp == -1)
						ans = 0;
					else
						ans = m(ans * temp);
					prev_x = j;
					break;
				}
			}
			i = j;
		}
		if (prev_x == n-2){
			ans = m(ans * 2LL);  // last swap
			ans = m(PowMod(2, one_c) * ans);
		} else if (prev_x == n-1 && type(n-2) != 0) // 2nd last is not 1 and last is 1 . jump ahead
			ans = 0;
		else if (prev_x != n-1){ // last not 1, 2nd last also not 1
			ans = 0;
		} else {
			ans = m(PowMod(2, one_c) * ans);
		}
		printf("%lld\n", ans);
	}

	return 0;
}