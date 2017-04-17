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

char board[26][26];
int r, c;

int main(){
	int t, i, j, tf, pr;
	char ch;
	ios_base::sync_with_stdio(0);
	cin >> t;

	for (tf=1; tf<=t; tf++){
		// nums
		cin >> r >> c;
		// take input
		for (i=0; i<r; i++){
			for (j=0; j<c; j++){
				cin >> board[i][j];
			}
		}
		// solve
		for (i=0; i<r; i++){
			ch = ' ';
			for (j=0; j<c; j++){
				if (board[i][j] != '?'){
					ch = board[i][j];
				} else if (ch != ' ') {
					board[i][j] = ch;
				}
			}
		}
		// first
		for (i=0; i<r; i++){
			for (j=0; j<c; j++){
				if (board[i][j] != '?')
					break;
			}
			if (j < c){
				ch = board[i][j];
				for (j=j-1; j>=0; j--)
					board[i][j] = ch;
			}
		}
		// copy
		pr = -1;
		for (i=0; i<r; i++){
			for (j=0; j<c; j++){
				if (board[i][j] != '?') break;
			}
			if (j < c) pr = i; 
			if (j == c && pr != -1){
				for (j=0; j<c; j++)
					board[i][j] = board[pr][j];
			}
		}
		// copy reverse
		pr = -1;
		for (i=r-1; i>=0; i--){
			for (j=0; j<c; j++){
				if (board[i][j] != '?') break;
			}
			if (j < c) pr = i; 
			if (j == c && pr != -1){
				for (j=0; j<c; j++)
					board[i][j] = board[pr][j];
			}
		}
		// print
		cout << "Case #" << tf << ":" << endl;
		for (i=0; i<r; i++){
			for (j=0; j<c; j++){
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
