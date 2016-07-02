#include "bits/stdc++.h"
#define MODULO 1000000007
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef string::iterator sit;
typedef string::reverse_iterator srit;
#define fout cout
ifstream fin("A-small-practice.in");
//ofstream fout("output.txt");

string Number2Base(int num, int base){
	int baselen = base<10 ? (ceil(10/(double) base) * ceil(log(num+1)/log(10))) : ceil(log(num+1)/log(10));
	int d, s=0;
	ull t;
	string out;
	for (int i=1; i<=baselen; i++){
		d = num / (t = pow(base, baselen-i));
		if (d>0) s=1;
		//if (s) out = out + (d>9 ? (char)(d+55) : (char)(d+48));
		if (s) out = out + (char)(d+48); // converted form for this ques
		num = num-(d*t);
	}
	return out;
}

int main(){
	int t, c, i;
	fin >> t;
	int tc = t;
	string s1, s2, s3, conv;
	int slen2, ans, slen3;
	int srcc[500];
	sit strit;
	srit strrit;

	while (t--){
		fin >> s1 >> s2 >> s3;
		slen2 = s2.size(), slen3 = s3.size();
		ans = 0;
		for (strit = s2.begin(), i=0; strit != s2.end(); strit++)
			srcc[*strit] = i++;
		for (strrit = s1.rbegin(), i=0; strrit != s1.rend(); strrit++)
			ans += pow(slen2, i++) * (srcc[*strrit]);
		conv = Number2Base(ans, slen3);
		for (strit = s3.begin(), i=0; strit != s3.end(); strit++)
			srcc[48 + i++] = *strit;
		fout << "Case #" << tc-t << ": ";
		for (strit = conv.begin(); strit != conv.end(); strit++)
			fout << (char) srcc[*strit];
		fout <<  endl;
	}
	return 0;
}