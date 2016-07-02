void insertionSort(int ar_size, int *  ar) {
	int k;
	int i, i0, s;

	for (i0=2; i0<=ar_size; i0++){
		k = ar[i0-1], s=0;

		for (i=i0-2; i>-1; i--){
			if (ar[i] >= k)
				ar[i+1] = ar[i];
			else if (ar[i] < k){
				ar[i+1] = k;
				s = 1;
				break;
			}
		}
		if (s==0)
			ar[0] = k;
	}
	
}