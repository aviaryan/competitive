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

char board[100][101];
bool visited[100][100];
int n,m,kf;
bool finished=0;

int isvalid(int i, int j){
	return (i >= 0 && i < n && j >= 0 && j < m && board[i][j] != 'X' && visited[i][j] == 0);
}

void findBoard(int * x, int * y, char c){
	int i,j;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			if (board[i][j] == c){
				*x = i;
				*y = j;
				break;
			}
}

void traverse(int i, int j, int k){
	if (finished) return;
	if (board[i][j] == '*'){
		finished = 1;
		kf = k;
		return;
	}

	visited[i][j] = 1;
	int ops = isvalid(i+1, j) + isvalid(i-1, j) + isvalid(i, j+1) + isvalid(i, j-1);
	if (ops > 1)
		k++;
	if (isvalid(i+1,j)) traverse(i+1, j, k);
	if (isvalid(i-1,j)) traverse(i-1, j, k);
	if (isvalid(i,j+1)) traverse(i, j+1, k);
	if (isvalid(i,j-1)) traverse(i, j-1, k);
}

int main(){
	int t, i, k, j, hi, hj, ei, ej;
	ios_base::sync_with_stdio(0);
	cin >> t;

	while (t--){
		cin >> n >> m;
		for (i=0; i<n; i++)
			cin >> board[i];
		cin >> k;
		findBoard(&hi, &hj, 'M');
		findBoard(&ei, &ej, '*');
		for (i=0; i<n; i++) fill_n(visited[i], m, 0);
		finished = 0;
		traverse(hi, hj, 0);
		cout << ((kf == k) ? "Impressed" : "Oops!") << endl;
	}

	return 0;
}