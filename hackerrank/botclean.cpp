#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int mx4(int a, int b, int c, int d, int * option){
	int i=1; // down , right , up , left
	int p = max(a, max(b, max(c, d)));
	if (p == a)
		*option = 1;
	else if (p == b)
		*option = 2;
	else if (p == c)
		*option = 3;
	else if (p == 4)
		*option = 4;
	return p;
}

int main(){
	int t, i, j, k, n;
	ios_base::sync_with_stdio(0);
	int x,y,ct=0,op;
	char b[5][5];
	cin >> x >> y;
	x++; y++;

	for (i=0; i<5; i++)
		for (j=0; j<5; j++){
			cin >> b[i][j];
			if (b[i][j] == 'd') ct++;
		}

	int arr[7][7], arrbk[7][7];
	for (i=0; i<7; i++){
		arr[i][0] = 0; arr[i][6] = 0;
		arr[0][i] = 0;
		arr[6][i] = 0;
	}

	for (i=1; i<=100; i++){
		for (j=1; j<=5; j++)
			for (k=1; k<=5; k++){
				if (i==1)
					arrbk[j][k] = ( (b[j-1][k-1] == 'd') ? 1 : 0 );
				else
					arrbk[j][k] = arr[j][k] + mx4( arr[j+1][k] , arr[j][k+1] , arr[j-1][k] , arr[j][k-1] , &op );
				if (j==x && k==y){
					if (arrbk[x][y] == ct){
						cout << op << ct << i << endl;
						break;
					}
				}
			}

		// copy
		for (j=1; j<=5; j++)
			for (k=1; k<=5; k++)
				arr[j][k] = arrbk[j][k];
	}
	return 0;
}