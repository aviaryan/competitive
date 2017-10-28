#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void insertion_sort(int *arr, int arr_size) {
	int i, key, j;
	for (i = 1; i < arr_size; i++) {
		key = arr[i];
		j = i - 1;
		/* Move elements of arr[0...i-1], that are
			greater than key, to one position ahead
			of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void mostFreq3(int *a, int n, int b[3]) {

// Write your code here
// hint: sort a, find biggest 3 blocks

	int i;
	int bad = -92321;
	insertion_sort(a, n);
	int prev = a[0], ct=1, unset;
	int mxsofar = 0, mxnum;

	// find
	prev = bad; mxsofar = 0, unset = 0; ct=0;
	for (i=0; i<n; i++){
		if (a[i] == bad || (a[i] != prev && i>0)){
			if (prev != bad && ct > mxsofar){
				mxsofar = ct; mxnum = prev;
			}
			if (a[i] != bad){
				prev = a[i]; ct = 1; unset=1;
			}
			continue;
		}
		if (i == 0 || unset == 0){
			unset = 1; prev = a[i]; ct = 1; continue;
		}
		if (a[i] == prev){
			ct++;
		}
	}
	if (prev != bad && ct > mxsofar) { mxsofar = ct; mxnum = prev; }
	b[0] = mxnum;

	// remove
	for (i=0; i<n; i++){
		if (a[i] == mxnum) a[i] = bad;
	}

	// find
	prev = bad; mxsofar = 0, unset = 0; ct=0;
	for (i=0; i<n; i++){
		if (a[i] == bad || (a[i] != prev && i>0)){
			if (prev != bad && ct > mxsofar){
				mxsofar = ct; mxnum = prev;
			}
			if (a[i] != bad){
				prev = a[i]; ct = 1; unset=1;
			}
			continue;
		}
		if (i == 0 || unset == 0){
			unset = 1; prev = a[i]; ct = 1; continue;
		}
		if (a[i] == prev){
			ct++;
		}
	}
	if (prev != bad && ct > mxsofar) { mxsofar = ct; mxnum = prev; }
	b[1] = mxnum;

	// remove
	for (i=0; i<n; i++){
		if (a[i] == mxnum) a[i] = bad;
	}

	// for(i=0; i<n; i++) cout << a[i] << endl;

	// find
	prev = bad; mxsofar = 0, unset = 0; ct=0;
	for (i=0; i<n; i++){
		if (a[i] == bad || (a[i] != prev && i>0)){
			if (prev != bad && ct > mxsofar){
				mxsofar = ct; mxnum = prev;
			}
			if (a[i] != bad){
				prev = a[i]; ct = 1; unset=1;
			}
			continue;
		}
		if (i == 0 || unset == 0){
			unset = 1; prev = a[i]; ct = 1; continue;
		}
		if (a[i] == prev){
			ct++;
		}
	}
	if (prev != bad && ct > mxsofar) { mxsofar = ct; mxnum = prev; }
	b[2] = mxnum;

	// remove
	for (i=0; i<n; i++){
		if (a[i] == mxnum) a[i] = bad;
	}
}


int main()
{
	int n;
	int a[100];
	int b[3];
	int i=0;

	cin >> n;
	for(i=0;i<n;i++){
		cin >> a[i];
	}

	mostFreq3(a,n,b);
        for(i=0; i<3; i++)
            cout << b[i] << " ";

	return 0;
}
