#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%s", a)
#define d(a) printf("%s", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int n, sqrtn;
map<int,ll> sorted;
int arr[1000000];
char str[1000000 + 1];

int forw[1000000];
int forwi[1000000];
int back[1000000];
int backi[1000000];
int forw_top, forwi_top, back_top, backi_top;

int fwd[1000000], bwd[1000000];
ll * ptrs[1000000];


int main(){
	int t, i, m, j, sptr=0;
	//ios_base::sync_with_stdio(0);
	scanf("%d %d", &n, &m);

	ll limit = ((ll) (n) * (ll) (n+1))/2;

	for (i=0; i<n; i++)
		scanf("%d", arr+i);

	for (i=0; i<n; i++){
		ptrs[i] = &(sorted[arr[i]] = 0);
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
			fwd[tind] = i-tind;
		}
		forw[++forw_top] = arr[i];
		forwi[++forwi_top] = i;
	}
	while (forwi_top >= 0){
		tind = forwi[forwi_top];
		fwd[tind] = n-tind; // doubt here
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
			bwd[tind] = tind-i;
		}
		back[++back_top] = arr[i];
		backi[++backi_top] = i;
	}
	while (backi_top >= 0){
		tind = backi[backi_top];
		bwd[tind] = tind + 1; // doubt here
		back_top--; backi_top--;
	}

	// MAKE ANS
	for (i=0; i<n; i++){
		*ptrs[i] += ( ((ll) bwd[i]) * ((ll) fwd[i]) );
	}

	// PROCESS ANS ARR
	ll csz = 0;
	map<int,ll>::reverse_iterator mmrit;

	for (mmrit = sorted.rbegin(); mmrit != sorted.rend(); mmrit++){
		mmrit->second += csz;
		csz = mmrit->second;
	}

	char sign, player, temp;
	int x;
	ll ans;
	map <int,ll>::iterator mit;
	while (m--){
		scanf("%c%c%c%d%c%c", &temp, &sign, &temp, &x, &temp, &player);
		if (sign == '>'){
			mit = sorted.upper_bound(x);
			if (mit == sorted.end())
				ans = 0;
			else
				ans = mit->second;
		} else if (sign == '<'){
			mit = sorted.lower_bound(x);
			if (mit == sorted.end())
				ans = limit;
			else
				ans = limit - mit->second;
		} else {
			mit = sorted.find(x);
			if (mit != sorted.end()){
				ans = mit->second;
				mit++;
				if (mit != sorted.end())
					ans -= mit->second;
			} else
				ans = 0;
		}

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