void sstrrev(char *s){
	int k;
	k = strlen(s);
	int i;
	char c;
	for (i=0; i<k/2; i++){
		c = s[i];
		s[i] = s[k-i-1];
		s[k-i-1] = c;
	}
}