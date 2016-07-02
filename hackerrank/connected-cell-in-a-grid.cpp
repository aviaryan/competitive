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

int board[10][10];
bool visited[10][10];
int n,m,kf;
bool finished=0;

int isvalid(int i, int j){
	return (i >= 0 && i < n && j >= 0 && j < m && board[i][j] != 0 && visited[i][j] == 0);
}

void traverse(int i, int j){
	visited[i][j] = 1;
	kf++;

	if (isvalid(i+1,j)) traverse(i+1, j);
	if (isvalid(i-1,j)) traverse(i-1, j);
	if (isvalid(i,j+1)) traverse(i, j+1);
	if (isvalid(i,j-1)) traverse(i, j-1);

	if (isvalid(i-1,j-1)) traverse(i-1, j-1);
	if (isvalid(i+1,j+1)) traverse(i+1, j+1);
	if (isvalid(i-1,j+1)) traverse(i-1, j+1);
	if (isvalid(i+1,j-1)) traverse(i+1, j-1);
}

int main(){
	int t, i, j, ans=0;
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++)
			cin >> board[i][j];
	for (i=0; i<n; i++) 
		fill_n(visited[i], m, 0);
	for (i=0; i<n; i++)
		for (j=0; j<m; j++){
			if (isvalid(i,j)){
				kf=0;
				traverse(i,j);
				ans = max(ans, kf);
			}
		}
		
	cout << ans << endl;

	return 0;
}