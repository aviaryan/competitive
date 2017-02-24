#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

typedef string::iterator sit;


int main(){
	string s;
	cin >> s;
	sit it;
	for (it = s.begin(); it != s.end(); it++){
		if (*it < 97)
			*it += 32;
		if (!(*it == 'a' || *it == 'e' || *it == 'y' || *it == 'u' || *it == 'o' || *it == 'i'))
			printf("%c%c", '.', *it);
	}

	return 0;
}