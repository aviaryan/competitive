#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);

	ll arr[101];
	arr[1] = 1;
	for (i=2; i<=100; i++)
		arr[i] = i*i + arr[i-1];
	
	cin >> t;
	while (t != 0){
		cout << arr[t] << endl;
		cin >> t;
	}



	return 0;
}