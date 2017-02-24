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

vector <int> childs[100001];
bool visited[100000+1];
int sums[100000+1];
int mindiff;
int arr[100000+1];
int ts;

int traverse(int i, int fromparent){
	vector <int>::iterator vit;
	int sum = arr[i];
	visited[i] = 1;
	for (vit = childs[i].begin(); vit != childs[i].end(); vit++){
		if (*vit == fromparent)
			continue;
		if (visited[*vit])
			sum += arr[*vit];
		else
			sum += traverse(*vit, i);
	}
	sums[i] = sum;
	//cout << sums[i] << " " << i << endl;
	mindiff = min( abs(ts-sum-sum) , mindiff );
	return sum;
}

int main(){
	int t, i, n, a, b;
	ios_base::sync_with_stdio(0);
	cin >> n;
	mindiff = MODULO, ts = 0;

	for (i=1; i<=n; i++){
		cin >> arr[i];
		ts += arr[i];
	}

	//cout << ts;

	for (i=1; i<n; i++){
		cin >> a >> b;
		childs[a].push_back(b);
		childs[b].push_back(a);
	}

	sums[1] = traverse(1, 0);

	cout << mindiff;

	return 0;
}

/*
6
100 200 100 500 100 600
1 2
2 3
2 5
4 5
5 6
*/