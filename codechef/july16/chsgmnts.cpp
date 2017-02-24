#include "bits/stdc++.h"
#define MODULO 1000000007
#define endl '\n'
#define m(a) ((a)%MODULO)
#define s(a) scanf("%d", &a)
#define sl(a) scanf("%lld", &a)
#define p(a) printf("%lld\n", a)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;


int main(){
	int t, j;
	s(t);
	map <int, set<int> > nums;
	set <int> seen;
	set <int> pos;
	set <int> temp;
	set <int>::iterator sit, pre_sit, next_sit;
	int arr[1000];
	ll ans, prev, i, n;

	while (t--){
		sl(n);
		nums.clear();
		ans = 0;
		// collect input
		for (i=0; i<n; i++){
			s(arr[i]);
			if (nums.find(arr[i]) == nums.end()){
				temp.clear();
				temp.insert(i);
				nums.insert(make_pair(arr[i], temp));
			} else {
				nums.find(arr[i])->second.insert(i);
			}
		}
		// solve
		for (i=0; i<(n-1); i++){
			pos.clear();
			seen.clear();
			pos.insert(i);
			pos.insert(n);
			prev = ((n-i-1) * (n-i-2) / 2) + (n-i-1);
			for (j=i; j>=0; j--){
				if (seen.find(arr[j]) == seen.end()){
					seen.insert(arr[j]);
					temp.clear();
					temp = nums.find(arr[j])->second;
					//printf("not in set i%lld %d\n", i, arr[i]);
					for (sit=temp.upper_bound(i); sit!=temp.end(); sit++){ // find all poss of arr[i]
						//printf("sit %d\n", *sit);
						pos.insert(*sit);
						pre_sit = pos.find(*sit);
						next_sit = pre_sit; //pos.upper_bound(*sit);
						pre_sit--; next_sit++;
						//printf("pre_Sit %d\n", *pre_sit);
						//printf("next sit %d\n", *next_sit);
						prev += ((*sit - *pre_sit - 1) * (*sit - *pre_sit - 2) / 2) + (*sit-*pre_sit-1);
						prev += ((*next_sit - *sit - 1) * (*next_sit - *sit - 2) / 2) + (*next_sit-*sit-1);
						prev -= ((*next_sit - *pre_sit - 1) * (*next_sit - *pre_sit - 2) / 2) + (*next_sit-*pre_sit-1);
					}
				}
				ans += prev;
				//p(ans);
			}
		}
		// print
		printf("%lld\n", ans);
	}

	return 0;
}