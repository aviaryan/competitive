#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%s", a)
#define d(a) printf("%s", a)
#define LTD 1000000
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n, sqrtn;
map<int,int> sorted[LTD + 1];
int arr[LTD];
char str[LTD + 1];

int forw[LTD];
int forwi[LTD];
int back[LTD];
int backi[LTD];
int forw_top, forwi_top, back_top, backi_top;

bool fwd[LTD], bwd[LTD];
int * ptrs[LTD];


map <int,int>::iterator ml;
int pc;

void the_upper_bound(int k){
	pc = (k-1)/1000;
	if ( ( ml = sorted[pc].upper_bound(k) ) == sorted[pc].end() )
		ml = sorted[pc+1].begin();
}

void the_lower_bound(int k){
	pc = (k-1)/1000;
	if ( ( ml = sorted[pc].lower_bound(k) ) == sorted[pc].end() )
		ml = sorted[pc+1].begin();
}

int main(){
	int t, i, m, j, sptr=0;
	scanf("%d %d", &n, &m);

	ll limit = ((ll) (n) * (ll) (n+1))/2;

	for (i=0; i<n; i++)
		scanf("%d", arr+i);

	for (i=0; i<n; i++){
		ptrs[i] = &(sorted[ (arr[i]-1)/1000 ][arr[i]] = 0);
	}

	int tind, tdat;
	forw_top = -1, forwi_top = -1, back_top = -1, backi_top = -1;

	// FORWARD
	forw[++forw_top] = MODULO; // to manage that while loop
	forw[++forw_top] = arr[0];
	forwi[++forwi_top] = 0;
	for (i=1; i<n; i++){
		while (forw[forw_top] <= arr[i]){
			tind = forwi[forwi_top];
			forw_top--;
			forwi_top--;
			fwd[tind] = (i-tind)%2;
		}
		forw[++forw_top] = arr[i];
		forwi[++forwi_top] = i;
	}
	while (forwi_top >= 0){
		tind = forwi[forwi_top];
		fwd[tind] = (n-tind)%2; // doubt here
		forw_top--; forwi_top--;
	}

	// BACKWARD
	back[++back_top] = MODULO; // to manage that while loop
	back[++back_top] = arr[n-1];
	backi[++backi_top] = n-1;
	for (i=n-2; i>=0; i--){
		while (back[back_top] < arr[i]){
			tind = backi[backi_top];
			back_top--;
			backi_top--;
			bwd[tind] = (tind-i)%2;
		}
		back[++back_top] = arr[i];
		backi[++backi_top] = i;
	}
	while (backi_top >= 0){
		tind = backi[backi_top];
		bwd[tind] = (tind + 1)%2; // doubt here
		back_top--; backi_top--;
	}

	// MAKE ANS
	for (i=0; i<n; i++){
		*ptrs[i] += ( bwd[i] * fwd[i] );
	}

	// PROCESS ANS ARR
	int csz = 0;
	map<int,int>::reverse_iterator mmrit;

	sorted[n][1] = 0; // last one
	for (i=LTD-1; i>=0; i--){
		if (sorted[i].size() > 0){
			for (mmrit = sorted[i].rbegin(); mmrit != sorted[i].rend(); mmrit++){
				mmrit->second = (mmrit->second + csz) % 2;
				csz = mmrit->second;
			}
		} else {
			sorted[i][1] = csz;
		}
	}

	char sign, player, temp;
	int x;
	int ans;
	int ilimit = (limit % 2LL) + 2; // safety belt

	map <int,int>::iterator mit;
	while (m--){
		scanf("%c%c%c%d%c%c", &temp, &sign, &temp, &x, &temp, &player);
		if (sign == '>'){
			the_upper_bound(x);
			ans = ml->second;
		} else if (sign == '<'){
			the_lower_bound(x);
			ans = ilimit - ml->second;
		} else {
			pc = (x-1)/1000;
			mit = sorted[pc].find(x);
			if (mit != sorted[pc].end()){
				ans = mit->second;
				mit++;
				if (mit == sorted[pc].end())
					mit = sorted[pc+1].begin();
				ans -= mit->second;
			} else
				ans = 0;
		}
		ans += 2; // safety belt

		//printf("%lld\n", ans);
		if (ans % 2)
			str[sptr++] = player;
		else
			str[sptr++] = (player=='C' ? 'D' : 'C');
	}

	str[sptr] = '\0';
	printf("%s", str);
	return 0;
}

/*
4 5
2 5 2 1
> 1 D
< 2 C
> 2 C
= 2 C
< 5 D
*/