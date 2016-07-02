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

int r,c;
int ct, ta;

void move(bool ** visited, bool ** arr, int i, int j){
	
	if (!arr[i][j]) // not allowed
		return;

	int ti, tj;
	visited[i][j] = 1;
	ct++;

	ti = i+1; tj=j;
	if (ti < r){
		if (!visited[ti][tj]) move(visited, arr, ti, tj);
	}

	ti = i-1; tj=j;
	if (ti >= 0){
		if (!visited[ti][tj]) move(visited, arr, ti, tj);
	}

	ti = i; tj=j-1;
	if (tj >= 0){
		if (!visited[ti][tj]) move(visited, arr, ti, tj);
	}

	ti = i; tj=j+1;
	if (tj < c){
		if (!visited[ti][tj]) move(visited, arr, ti, tj);
	}
}

int main(){
	int t, i, j;
	s(t);
	char tc;

	while (t--){
		scanf("%d %d%c", &r, &c, &tc);
		bool arr[r][c];
		bool visited[r][c];

		ta=0;
		for (i=0; i<r; i++){
			for (j=0; j<c; j++){
				scanf("%c", &tc);
				if (tc == 'o'){
					arr[i][j] = 1;
					ta = 1;
				}
				else arr[i][j] = 0;
			}
			scanf("%c", &tc); // linefeed
		}

		ct = 0;
		move(visited, arr, 0, 0);


	}

	return 0;
}