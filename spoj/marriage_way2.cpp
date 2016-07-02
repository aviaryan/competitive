#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int t;
	cin >> t;

	while (t--){
		int n,m;
		cin >> n >> m;
		int i, a, b, j;
		bool rels[n][n];

		for (i=0; i<n; i++)
			fill_n(rels[i], n, 0);

		for (i=0; i<m; i++) {
			cin >> a >> b;
			a--, b--;
			rels[a][b] = 1;
			rels[b][a] = 1;
		}

		string str;
		int beliefs[n];
		for (i=0; i<n; i++){
			cin >> str;
			if (str.compare("Love") == 0) beliefs[i] = 1;
			else beliefs[i] = 0;
		}

		// most marne-wala (incompatible) banda
		int neg[n], deathnote=0;
		fill_n(neg, n, -1);
		for (i=0; i<n; i++){
			//lct = 0;
			for (j=0; j<n; j++)
				if (rels[i][j])
					if (beliefs[i] == beliefs[j]) neg[i]--;
					else neg[i]++; //, deathnote++;
			//if (lct==1) neg[i]++;
			// if (lct == 1 && neg[i]==1)
			// 	neg[i] = 0;
		}

		int ans=0, maxind, max;
		bool chngdone[n];
		fill_n(chngdone, n, 0);

		while (1){
			// find max occur
			max = 0;
			for (i=0; i<n; i++)
				if (chngdone[i] == 0)
					if (neg[i]>max) max = neg[i], maxind = i;
			if (max == 0) break;
			for (i=0; i<n; i++)
				if (rels[maxind][i])
					if (beliefs[maxind] == beliefs[i]) neg[i]++;
					else neg[i]--;
			chngdone[maxind] = 1;
			beliefs[maxind] = !beliefs[maxind];
			//ans+= neg[maxind];
			ans++;
			neg[maxind] = -1*max;
		}

		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				if (rels[i][j])
					if (beliefs[i] != beliefs[j])
						deathnote++;
		deathnote/=2;

		cout << "Number of Deaths: " << deathnote+ans << endl;
	}
	
	return 0;
}