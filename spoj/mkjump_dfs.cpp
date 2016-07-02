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

bool board[10][10];
bool visited[10][10];
int ans;

bool possible(int x, int y){
	if (x > 9 || x < 0 || y > 9 || y < 0)
		return 0;
	if (!board[x][y])
		return 0;
	if (visited[x][y])
		return 0;

	return 1;
}

void solve_dfs(int x, int y, int cur){
	
	visited[x][y] = 1;
	ans = max(ans, cur);

	if (possible(x-2, y-1)) solve_dfs( x-2, y-1, cur+1 );
	if (possible(x-2, y+1)) solve_dfs( x-2, y+1, cur+1 );
	if (possible(x+2, y-1)) solve_dfs( x+2, y-1, cur+1 );
	if (possible(x+2, y+1)) solve_dfs( x+2, y+1, cur+1 );

	if (possible(x-1, y-2)) solve_dfs( x-1, y-2, cur+1 );
	if (possible(x-1, y+2)) solve_dfs( x-1, y+2, cur+1 );
	if (possible(x+1, y-2)) solve_dfs( x+1, y-2, cur+1 );
	if (possible(x+1, y+2)) solve_dfs( x+1, y+2, cur+1 );

	visited[x][y] = 0;
}

int main(){
	int t=0, i, n, of, sz, j, total, st;
	s(n);

	while (n != 0){
		for (i=0; i<10; i++){
			fill_n(board[i], 10, 0);
			fill_n(visited[i], 10, 0);
		}
		total = 0;
		for (i=0; i<n; i++){
			scanf("%d %d", &of, &sz);
			fill_n( board[i] + of , sz , 1 );
			total += sz;
		}

		for (st=0; st<10; st++)
			if (board[0][st])
				break;
		
		ans=0;
		solve_dfs(0, st, 1);
		ans = total-ans;

		t++;
		printf("Case %d, %d %s can not be reached.\n", t, ans, (ans==1) ? "square" : "squares");
		s(n);
	}

	return 0;
}