
// use quicksort for first lex

void nextlex(int *arr, int size){
	int i, k=-1, j, t;

	for (i=0; i<size-1; i++){
		if (arr[i] < arr[i+1])
			k = i;
	}
	// already largest
	if (k==-1)
		return;

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

}