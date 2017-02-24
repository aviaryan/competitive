#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

typedef vector<int> vi;
typedef vi::iterator vit;

char strmain[5001];
int str[5001];
multiset<int> pairs;
int n;
ull facts[5001];
set<int> breakp;
int nums[5001];

void initfacts(){
	ull i;
	facts[0] = 1; facts[1] = 1;
	for (i=2; i<=5000; i++)
		facts[i] = m(i*facts[i-1]);
}

void initnums(){
	int i;
	for (i=0; i<=5000; i++)
		nums[i] = i;
}

ll PowMod(int bs, int n)
{ // base^n % modULO
    ll ret = 1;
    ll a = bs;
    while (n > 0) {
        if (n & 1) ret = ret * a % MODULO;
        a = a * a % MODULO;
        n >>= 1;
    }
    return ret;
}

ull combination(ll n, ll r){
	return m( facts[n] * m( PowMod(m(facts[r] * facts[n-r]), MODULO-2) ) );
}

void makepairs(vi z){
	int i, k = z.size();
	pairs.insert(k);
	vi arr[26];

	// if ( ( (z.back() - z.front() + 1) == k ) && (k > 2) ){ // aaaa...
	// 	z.erase( z.begin() );
	// 	arr[ str[z.front()] ] = z;
	// } else {
		vit shit;
		for (shit = z.begin(); shit != z.end(); shit++){
			if (*shit >= n) 
				break;
			i = *breakp.lower_bound(*shit);
			if (i - (*shit) > 1){
				arr[ str[*shit] ].insert( arr[str[*shit]].end(), &nums[*shit+1], &nums[i] );
				shit+=(i-(*shit)-1);
			}
			else
				arr[ str[*shit] ].push_back(*shit+1);
		}
	//}

	for (i=0; i<26; i++){
		if (arr[i].size() > 1)
			makepairs(arr[i]);
	}
}

int main(){
	int t, i;
	ios_base::sync_with_stdio(0);
	cin >> t;
	int q, k;
	initfacts();
	initnums();
	multiset<int>::iterator mit;
	ull ans;
	ll ansarr[5001];
	char pre;

	while (t--){
		cin >> n >> q;
		cin >> strmain;
		vi arr[26];
		pairs.clear();

		// parse
		str[0] = strmain[0]-97; pre = strmain[0];
		for (i=1; i<n; i++){
			str[i] = strmain[i]-97;
			if (strmain[i] != pre)
				breakp.insert(i);
			pre = strmain[i];
		}
		breakp.insert(n);

		// precalc
		for (i=0; i<n; i++)
			arr[ str[i] ].push_back(i+1);
		for (i=0; i<26; i++){
			if (arr[i].size() > 1)
				makepairs(arr[i]);
		}

		// answer
		fill_n(ansarr, 5001, -1);
		for (i=0; i<q; i++){
			cin >> k;
			if (k==1){
				cout << (n*(n+1))/2 << endl;
				continue;
			}
			if (k>n){
				cout << 0 << endl;
				continue;
			}
			if (ansarr[k] != -1){
				cout << ansarr[k] << endl;
				continue;
			}
			mit = pairs.lower_bound(k);
			ans = 0;
			for ( ; mit != pairs.end(); mit=pairs.upper_bound(*mit) ){
				ans = m( ans + m( pairs.count(*mit) * combination(*mit, k) ) );
			}
			cout << ans << endl;
			ansarr[k] = ans;
		}
	}

	return 0;
}