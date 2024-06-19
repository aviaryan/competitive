// you can use includes, for example:
// #include <algorithm>

#include "bits/stdc++.h"
using namespace std;


int solution(string &S) {
    int len = S.size();
    char s[len+1];
    for (i=0; i<len; i++) 
    	s[i] = S.charAt(i);
    s[len] = '\0';
  	cout << s << endl;
}


int main(){
	int i;
	string s = "codecode";
	cout << solution(s) << endl;
	return 0;
}
