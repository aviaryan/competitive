#include "bits/stdc++.h"
using namespace std;


int solution(vector<int> &A) {
	int gct = 0, gmax, lgmax;
    vector<int> srt(A);
    sort(srt.begin(), srt.end());

    set <int> s;
	vector<int>::iterator vit, sit;

	vit = A.begin();
	gmax = 0;

	for (sit = srt.begin(); sit != srt.end(); sit++){
		// cout << *vit << endl;
		// min not found
		if (s.find(*sit) == s.end()){
			// find the group
			lgmax = *vit;
			while (true){
				s.insert(*vit);
				if (*vit != *sit){
					lgmax = max(lgmax, *vit); // find group max
					vit++;
				} else {
					// group found
					vit++;
					if (*sit > gmax){ // only if local max is more than prev group max
						gct++;
					}
					break;
				}
			}
			gmax = max(lgmax, gmax);
		} else {
			// do nothing
		}
	}

	return gct;
}


int main(){
	int t, i;
	// int arr[] = {1,2,3,4,5,10,9,8,11,7}; // ans 6
	// int arr[] = {4,3,2,6,1}; // ans 1
	// int arr[] = {1,2,3,4,5,10,6,9,8,11,7}; // ans 6
	vector<int> a;
	a.insert(a.begin(), arr, arr + (sizeof(arr)/sizeof(arr[0])));

	cout << solution(a) << endl;
	return 0;
}
