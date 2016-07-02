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
	int t, i, a, b;
	ios_base::sync_with_stdio(0);
	//cin >> t;
	cin >> a >> b;
	int arr[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
	int sum = 0;

	for (i = a; i <= b; i++){
		t = i;
		while (t > 0){
			sum += arr[t%10];
			t /= 10;
		}
	}
	cout << sum << endl;
	return 0;
}