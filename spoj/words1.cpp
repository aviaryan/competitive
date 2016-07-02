#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef vector<int> vi;
typedef vector<int>::iterator vii;
typedef unsigned long long ull;
typedef long long ll;

#define MODULO 1000000007

int main(){
	int t, n, onec, monec, i;
	cin >> t;
	string str;

	while (t--){
		cin >> n;
		int sts[26] = {0};

		while (n--){
			cin >> str;
			sts[ (int) str[0] - 97 ]++;
			sts[ (int) str[ str.size() - 1] - 97 ]--;
		}

		onec = 0; monec=0;
		for (i=0; i<26; i++)
			if (sts[i] > 0)
				onec += sts[i];
			else if (sts[i] < 0)
				monec += sts[i];

		if (onec * monec == -1 || onec * monec == 0) // onec = 1, monec = -1
			cout << "Ordering is possible." << endl;
		else
			cout << "The door cannot be opened." << endl;

	}

	return 0;
}