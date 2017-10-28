#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

int main(){
	int t, i, k;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int arr_even[t], arr_odd[t], ect=0, oct=0;

	for (i=0; i<t; i++){
		cin >> k;
		if (k % 2 == 0){
			arr_even[ect++] = k;
		} else {
			arr_odd[oct++] = k;
		}
	}

	sort(arr_even, arr_even+ect);
	sort(arr_odd, arr_odd+oct);

	for (i=0; i<ect; i++) {
		cout << arr_even[i] << " ";
	}
	for (i=oct-1; i>=0; i--) {
		cout << arr_odd[i] << " ";
	}

	cout << endl;

	return 0;
}
