#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef set<int> si;
typedef si::iterator siit;
typedef vector< pair<int, int> > vpii;

ifstream fin("B-small-attempt2.in");
ofstream fout("output.txt");


int solvenine(int *pk, si ns, int flag){

	int i, ans=0, maxd=0, rflag=0;
	siit nsit;
	vpii poss_ans;
	vpii::iterator iposs_ans;
	int nsitn;

	int p[1001];
	for (i=0; i<1001; i++)
		p[i] = pk[i];

	while (1){
		if (ns.begin() == ns.end())
			break;
		nsit = --(ns.end());
		nsitn = *nsit;

		if (nsitn == 1){
			poss_ans.push_back( make_pair(ans, 1) );
			ans += 1;
			break;
		}

		if (nsitn == 9 && flag==1) rflag = 1;

		if (nsitn % 2 == 0){
			ns.insert(nsitn/2);
			p[nsitn/2] += (p[nsitn] * 2);
		} else {
			if (rflag){
				ns.insert(3);
				p[3] += (p[9]*3);
			} else {
				ns.insert(nsitn/2);
				ns.insert( (nsitn/2) + 1 );
				p[nsitn/2] += p[nsitn];
				p[ (nsitn/2) + 1 ] += p[nsitn];
			}
		}
		poss_ans.push_back( make_pair(ans, nsitn) );
		if (rflag) 
			ans += (p[9]*2);
		else
			ans += p[nsitn];
		p[nsitn] = 0;
		ns.erase( nsit );
		rflag = 0;
	}

	// back check to see if there were possible better solutions
	maxd = 1;
	while (maxd){
		maxd = 0;
		for (iposs_ans = poss_ans.begin() ; iposs_ans != poss_ans.end() ; ++iposs_ans){
			i = (ans - iposs_ans->first) - iposs_ans->second;
			if (i>0)
				if (i>maxd) maxd = i;
		}
		ans -= maxd;
	}

	return ans;
}

int main(){
	int t, j, i;
	fin >> t;
	int d, p[1001], pt, ans, maxd;
	si ns; siit nsit;
	vpii poss_ans;
	vpii::iterator iposs_ans;
	int nsitn;

	for (j=1; j<=t; j++){
		fin >> d;
		fill_n(p, 1001, 0);
		ns.clear(); ans=0;
		poss_ans.clear();

		for (i=0; i<d; i++){
			fin >> pt;
			p[pt]++;
			ns.insert(pt);
		}

		ans = min( solvenine(p, ns, 0), solvenine(p, ns, 1) );
		fout << "Case #" << j << ": " << ans << endl;
	}
	
	return 0;
}