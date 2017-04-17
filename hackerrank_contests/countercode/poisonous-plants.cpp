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
	int t, i, n;
	ios_base::sync_with_stdio(0);
	cin >> n;
	int arr[n];

	for (i=0; i<n; i++)
		cin >> arr[i];
	
	int days[n], mx=0;
	fill_n(days, n, 0);
	int leftM[n];

	for (i=1; i<n; i++){
		if (arr[i] > arr[i-1]){
			leftM[i] = arr[i-1];
			if (days[i-1] > 0) leftM[i] = leftM[i-1];
			days[i] = 1;
			mx = max(1, mx);
		} else {
			if (days[i-1] > 0)
				if (leftM[i-1] < arr[i]){
					leftM[i] = leftM[i-1];
					days[i] = days[i-1]+1;
					mx = max(days[i], mx);
				}
		}
	}

	cout << mx;
	return 0;
}