#include "bits/stdc++.h"
#define MODULO 1000000007
#define m(a) ((a)%MODULO)
using namespace std;

typedef unsigned long long ull;
typedef long long ll;

class BinaryCode {
public:
	vector <string> decode(string s){
		string::iterator st;
		string zer, one;
		char pzer='0', pone='0', a='0', b='1', tmpa, tmpb;
		bool faila=0, failb=0;

		for (st = s.begin(); st != s.end(); st++){
			tmpa = *st - a - pzer + 96;
			tmpb = *st - b - pone + 96;
			pzer = a; pone = b;
			if (a != '0' && a != '1') faila = true;
			if (b != '0' && b != '1') failb = true;
			zer.push_back(a); one.push_back(b);
			a = tmpa; b = tmpb;
		}
		vector <string> k;
		k.push_back(faila ? "NONE" : (a=='0') ? zer : "NONE"); k.push_back(failb ? "NONE" : (b=='0') ? one : "NONE");
		return k;
	}
};

// int main(){
// 	int t, i;
// 	BinaryCode p = BinaryCode();
// 	vector<string> s = p.decode("131");

// 	for (vector<string>::iterator st = s.begin(); st != s.end(); st++){
// 		cout << *st << endl;
// 	}
// 	return 0;
// }