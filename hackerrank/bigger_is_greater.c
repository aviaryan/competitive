#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

// use quicksort for first lex

int nextlex_str(char *arr, int size){
	int i, k=-1, j;
	char t;

	for (i=0; i<size-1; i++){
		if (arr[i] < arr[i+1])
			k = i;
	}
	// already largest
	if (k==-1)
		return 1; // error

	for (i=k+1; i<=size-1; i++){ // find largest greater than this ahead of it
		if (arr[i] > arr[k])
			j = i;
	}

	t = arr[k]; 	// swap them
	arr[k] = arr[j];
	arr[j] = t;

	// reverse after k
	int sl = (size-k-1);
	for (i=0; i<(sl/2); i++){
		t = arr[k+1+i];
		arr[k+1+i] = arr[size-i-1];
		arr[size-i-1] = t;
	}

	return 0;
}


int main(){
	int t, e;
	scanf("%d", &t);
	char str[101];

	for (;t>0;t--){
		scanf("%s", str);
		e = nextlex_str(str, strlen(str));
		printf("%s\n", e==0 ? str : "no answer");
	}
	return 0;
}