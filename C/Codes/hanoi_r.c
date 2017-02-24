#include <stdio.h>
#include <math.h>
#include <malloc.h>

int n, *discs, lst;

char int2stck(int a);

main(){
	int t1, t2;
	printf("Please enter the number of rings in question - ");
	scanf("%d", &n);
	discs = (int*) calloc(n, sizeof(int));
	
	// fill first stack with 1s
	for (t1=1; t1<=n; t1++ )
		discs[t1-1] = 1;
	
	// impress user
	printf("\nFinal stack will end in %c", n%2==0 ? 'c' : 'b');
	int ts = (int) pow(2,n)-1.0;
	printf("\nTotal number of steps the process takes : %d\n", ts );
	
	// wait for them to read
	printf("\nPress 1 to show transistion steps ...\n");
	int t10=0;
	scanf("%d", &t10);

	// start process
	int dm, fp, ip;
	for(t2=0; t2<ts; t2++){
		dm = disc_to_move();
		ip = discs[dm-1];
		fp = discs[dm-1]+ (dm%2==0 ? 2 : 1); // if even disc then moves 2 steps right
		if (fp>3)
			fp = fp%3;
		discs[dm-1] = fp;
		lst = dm;
		printf("%c > %c\n", int2stck(ip), int2stck(fp));
	}

}

int disc_to_move(){
	int topper[3] = {n+1, n+1, n+1}, i,j,r;
	
	for (i=0; i<n; i++){
		for (j=0;j<3;j++)
			if (topper[j] == n+1 && discs[i] == j+1){
				topper[j] = i+1;
				if (lst == i+1)
					topper[j] = n+2; // too big
			}
	}
	// compare
	for (j=0;j<3;j++)
		if (topper[j] < topper[(j+1)%3] && topper[j] < topper[(j+2)%3])
			r = topper[j];
	return r;
}

char int2stck(int a){
	char z;
	if (a==1) z = 'a';
	else if (a==2) z = 'b';
	else if (a==3) z = 'c';
	return z;
}