#include <iostream>
#include <string>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int t;
	cin >> t;

	while (t--){
		int n,m;
		cin >> n >> m;
		int i, a, b, j;
		bool rels[n][n];
		int occurs[n];
		fill_n(occurs, n, 0);

		for (i=0; i<n; i++)
			fill_n(rels[i], n, 0);

		for (i=0; i<m; i++) {
			cin >> a >> b;
			a--, b--;
			rels[a][b] = 1;
			rels[b][a] = 1;
			occurs[a]++;
			occurs[b]++;
		}

		string str;
		int beliefs[n];
		for (i=0; i<n; i++){
			cin >> str;
			if (str.compare("Love") == 0) beliefs[i] = 1;
			else beliefs[i] = 0;
		}

		// trim list
		for (i=0; i<n; i++)
			for (j=0; j<n; j++)
				if (rels[i][j])
					if (beliefs[i] == beliefs[j])
						rels[i][j] = rels[j][i] = 0, occurs[i]--, occurs[j]--;

		int ans=0, maxind, max;
		while (1){
			// find max occur
			max = 0;
			for (i=0; i<n; i++)
				if (occurs[i]>max) max = occurs[i], maxind = i;
			if (max == 0) break;
			for (i=0; i<n; i++)
				if (rels[maxind][i]) occurs[i]--;
			occurs[maxind] = 0;
			ans++;
		}

		cout << "Number of Deaths: " << ans << endl;
	}
	
	return 0;
}