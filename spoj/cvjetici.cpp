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

#define LT 100000
int arr[LT+1];
int cut[LT+1];

void updateBIT(int ind, int v){
	while (ind <= LT){
		arr[ind] += v;
		ind += ind&(-ind);
	}
}

int getSum(int ind){
	int sum = 0;
	while (ind > 0){
		sum += arr[ind];
		ind -= ind&(-ind);
	}
	return sum;
}

int main(){
	int t, i, l, r, n, a, b;
	s(n);

	while (n--){
		scanf("%d %d", &l, &r);
		a = getSum(l);
		b = getSum(r);
		printf("%d\n", a + b - cut[l] - cut[r]);
		cut[l] = a;
		cut[r] = b;

		updateBIT(l+1, 1);
		updateBIT(r, -1);
	}

	return 0;
}