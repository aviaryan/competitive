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
	int t, i, sum;
	ios_base::sync_with_stdio(0);
	cin >> n;
	int arr[n];

	for (i=0; i<n; i++){
		cin >> arr[i];
		sum += arr[i];
	}

	int srt = sqrt(sum);
	vector <int> factors;
	for (i=1; i<=srt; i++){
		if (sum % i != 0) continue;
		factors.push_back(i);
		if ( (sum/i) != srt )
			factors.push_back( sum / i );
	}

	vector <int>::iterator vit;
	for (vit = factors.begin(); vit != factors.end(); vit++){
		
	}

	return 0;
}