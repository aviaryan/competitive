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

struct sizeCell {
	int i,j,size;
};
typedef struct sizeCell sc;

bool board[15][15];
int n, m;
vector <sc> maxsize;


int maxStrech(int i, int j, int dx, int dy){
	int ans = 1;
	i += dy;
	j += dx;
	while ((i >= 0) && (i < n) && (j >= 0) && (j < m) && (board[i][j] == true)){
		ans++;
		i += dy;
		j += dx;
	}
	return ans;
}

sc iamnoob(int i, int j, int size){
	sc s;
	s.i = i;
	s.j = j;
	s.size = size;
	return s;
}

void populate(){
	int i,j,ms, left, right, top, bottom;
	for (i=0; i<n; i++){
		for (j=0; j<m; j++){
			if (board[i][j] == false)
				continue;

			left = maxStrech(i, j, -1, 0);
			right = maxStrech(i, j, 1, 0);
			top = maxStrech(i, j, 0, -1);
			bottom = maxStrech(i, j, 0, 1);

			ms = min(min(min(left, right), top), bottom);
			if (ms > 1)
				maxsize.push_back(iamnoob(i,j,ms));
			//printf("%d %d %d\n", i, j, ms);
		}
	}
}


bool checkClear(int i1, int i2, int j1, int j2, int s1, int s2){
	bool temp[n][m], b;
	int i, j;
	for (i=0; i<n; i++)
		for (j=0; j<m; j++) temp[i][j] = false;
	temp[i1][j1] = true;
	for (i=1; i<s1; i++){
		temp[i1-i][j1] = temp[i1+i][j1] = temp[i1][j1+i] = temp[i1][j1-i] = true;
	}
	if (temp[i2][j2]) return false;
	for (i=1; i<s2; i++){
		b = temp[i2-i][j2] || temp[i2+i][j2] || temp[i2][j2+i] || temp[i2][j2-i];
		if (b)
			return false;
	}
	return true;
}


int main(){
	int t, i, j;
	scanf("%d %d", &n, &m);
	char c;
	int plusct = 0;
	char str[m+1];

	for (i=0; i<n; i++){
		scanf("%s", str);
		for (j=0; j<m; j++){
			c = str[j];
			board[i][j] = (c == 'G') ? true : false;
			if (c == 'G') plusct++;
		}
	}

	populate();

	int ans = (plusct>1);

	vector<sc>::iterator itsc, jtsc;
	int i1, j1, i2, j2, s1, s2;
	bool clear;

	for (itsc = maxsize.begin(); itsc != maxsize.end(); itsc++){
		// loop all pluses
		s1 = itsc->size;
		if ( (4*s1-3) < plusct ) ans = max(4*s1-3, ans);
		jtsc = itsc;
		jtsc++;

		for (;jtsc != maxsize.end(); jtsc++){
			// loop all pluses
			i1 = itsc->i, i2 = jtsc->i;
			j1 = itsc->j, j2 = jtsc->j;
			s1 = itsc->size, s2 = jtsc->size;
			//printf("%d %d %d %d", i2, i1, j2, j1);
			clear = checkClear(i1, i2, j1, j2, s1, s2); // (((abs(i2-i1)+1) >= (s2+s1)) || ((abs(j2-j1)+1) >= (s2+s1)));
			if (clear == true)
				ans = max( (4*s2-3)*(4*s1-3), ans);
			else {
				// not clear
				for (i=s2; i>1; i--){
					j = s1;
					clear = checkClear(i1, i2, j1, j2, j, i);
					if (clear == true){
						ans = max( (4*j-3)*(4*i-3), ans);
						break;
					}
					for (; j>1; j--){
						clear = checkClear(i1, i2, j1, j2, j, i);
						if (clear == true){
							ans = max( (4*j-3)*(4*i-3), ans);
							break;
						}
					}
				}
			}

		}
	}

	printf("%d", ans);

	return 0;
}