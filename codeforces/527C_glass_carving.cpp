#include <bits/stdc++.h>

using namespace std;
#define MODULO 1000000007

typedef vector<int> vi;
typedef vector<int>::iterator vii;
typedef unsigned long long ull;
typedef long long ll;

typedef set<int>::iterator sii;
typedef multiset<int>::iterator msii;

int main(){
	int w,h,n,k;
	scanf("%d %d %d", &w, &h, &n);
	char inch[4];

	set<int> ws, hs;
	multiset<int> wd, hd;
	ws.insert(0); ws.insert(w);
	hs.insert(0); hs.insert(h);
	wd.insert(w); hd.insert(h);

	sii setit, setit2;
	int maxw=w, maxh=h;

	while (n--){
		scanf("%s %d", inch, &k);
		if (inch[0] == 'H')
			hs.insert(k);
		else 
			ws.insert(k);

		if (inch[0] == 'V'){
			setit = ws.find(k);
			setit2 = ++setit;
			--(--setit);
			wd.erase( wd.find(*setit2 - *setit) );
			wd.insert( k - *setit);
			wd.insert( *setit2-k );
			maxw = *(--wd.end());
		}
		else {
			setit = hs.find(k);
			setit2 = ++setit;
			--(--setit);
			hd.erase( hd.find(*setit2 - *setit) );
			hd.insert( k - *setit);
			hd.insert( *setit2-k );
			maxh = *(--hd.end());
		}

		printf("%I64d\n", (ll) maxw * maxh);
	}
	return 0;
}