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
	s(t);
	ll arr[10], arr2[12], temp;
	vector <ll> v;
	bool add_mode;

	while (t--){
		s(n);
		fill_n(arr2, 12, 0);
		for (i=0; i<n; i++){
			scanf("%lld", &arr[i]);
			arr2[i] = arr[i];
		}
		if (n % 2 == 0){
			if (n == 2){
				// 1110000
				// 10000011
				arr2[0] = 1;
				arr2[1] = arr[1] + 1;
				arr2[2] = arr[0] - 1; // 1 taken
			} else {
				// 111000011110000
				// 111000100000111
				arr2[n-3] = arr[n-3] - 1;
				arr2[n-2] = 1;
				arr2[n-1] = arr[n-1] + 1;
				arr2[n] = arr[n-2] - 1;
			}
		} else {
			if (n == 1){
				arr2[0] = 1;
				arr2[1] = 1;
				arr2[2] = arr[0] - 1;
			} else {
				// 111000011
				// 111000101
				arr2[n-2] = arr[n-2] - 1;
				arr2[n-1] = 1;
				arr2[n] = 1;
				arr2[n+1] = arr[n-1] - 1;
			}
		}
		// make ans
		add_mode = false;
		v.clear();
		for (i=0; i<12; i++){
			if (add_mode){
				if (arr2[i] == 0) // will only happen if B ends
					continue;
				temp = v.back();
				v.pop_back();
				v.push_back(temp + arr2[i]);
				add_mode = false;
			} else {
				if (arr2[i] == 0){
					add_mode = true;
				} else {
					v.push_back(arr2[i]);
				}
			}
		}
		// print
		printf("%lu\n", v.size());
		for (vector<ll>::iterator vit = v.begin(); vit != v.end(); vit++)
			printf("%lld ", *vit);
		printf("\n");
	}

	return 0;
}