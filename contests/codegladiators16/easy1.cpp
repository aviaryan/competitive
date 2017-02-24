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


int passCount(int n,int m,int l)
{
	//Write code here
	if (l<=0) return -1;

	int guys[n];
	int i;
	for (i=0; i<n; i++) 
		guys[i] = 0;
	int ans=0, cur=0;
	while (true){
		guys[cur] += 1;
		if (guys[cur] == m)
			break;
		ans++;
		if (guys[cur]%2 == 0)
			cur = (cur-l+n)%n;
		else
			cur = (cur+l)%n;
	}
	return ans;
}


int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> n >> l >> m;
	cout << passCount(n, l, m) << endl;

	return 0;
}