#include <stdio.h>
#include <math.h>

int n;

void printStatus(int stack[]);

main(){
	int t1, t2;
	printf("Please enter the number of rings in question - ");
	scanf("%d", &n);
	int sk[4][n];
	
	// fill first stack with 1s
	for (t1=1; t1<=n; t1++ )
		sk[1][t1-1] = 1, sk[2][t1-1] = 0, sk[3][t1-1] = 0;
	
	// final posn
	char final;
	if (n%2==0)
		final = 'c';
	else final = 'b';
	
	// impress user
	printf("\nFinal stack will end in %c", final);
	int ts = (int) pow(2,n)-1.0;
	printf("\nTotal number of steps the process takes : %d\n", ts );
	
	// wait for them to read
	printf("\nPress 1 to show transistion steps ...\n");
	int t10=0;
	scanf("%d", &t10);
	
	// start process
	int ct=0, mids=0, gowh;
	int lstfrom=0, lstto=0;
	int s[4];
	int tfrom,tto,done=0;
	
	for(t2=1; t2<=n; t2++){
		mids = (int) pow(2,t2)-pow(2,t2-1); // stps reqd for each new integer stck
		gowh = (t2%2==0) ? 1 : 0; // 1 for new disc
		lstfrom = 4;

		printf("\n\tstart of new %d", t2);
		printStatus(sk[1]);
		printStatus(sk[2]);
		printStatus(sk[3]);
		for(ct=1; ct<=mids; ct++){ //ct=2 hour of action
			s[1] = topmost_disc(sk[1]);
			s[2] = topmost_disc(sk[2]);
			s[3] = topmost_disc(sk[3]);
			// transfer
			// precond

			done = 0;
			while (done==0)
			{

			done = 1;
			if (ct==2) {
				// printf(" hi here ");
				if (gowh==1){
					tto = (lstto==2) ? 2 : 3;
					tfrom = (lstto==2) ? 3 : 2;
				} else {
					tto = 1;
					tfrom = (lstto==2) ? 3 : 2;
				}
				sk[tfrom][s[tfrom]] = 0, sk[tto][s[tfrom]] = 1, lstto = tto, lstfrom = tfrom, printprg(lstto, lstfrom);
			}
			// bto c and c to b priority
			else if (s[1]<s[2] && lstto != 1 && (lstfrom != 2 || s[2] == n+1) ) // a to b
				sk[1][s[1]] = 0, sk[2][s[1]] = 1, lstto = 2, lstfrom = 1, printprg(lstto, lstfrom);
			else if (s[2]<s[1] && lstto != 2 && (lstfrom != 1 || s[1] == n+1) ) // b to a
				sk[2][s[2]] = 0, sk[1][s[2]] = 1, lstto = 1, lstfrom = 2, printprg(lstto, lstfrom);
			else if (s[2]<s[3] && lstto != 2 && (lstfrom != 3 || s[3] == n+1) ) // b to c
				sk[2][s[2]] = 0, sk[3][s[2]] = 1, lstto = 3, lstfrom = 2, printprg(lstto, lstfrom);
			else if (s[3]<s[2] && lstto != 3 && (lstfrom != 2 || s[2] == n+1) ) // c to b
				sk[3][s[3]] = 0, sk[2][s[3]] = 1, lstto = 2, lstfrom = 3, printprg(lstto, lstfrom);
			else if (s[1]<s[3] && lstto != 1 && (lstfrom != 3 || s[3] == n+1) ) // a to c
				sk[1][s[1]] = 0, sk[3][s[1]] = 1, lstto = 3, lstfrom = 1, printprg(lstto, lstfrom);
			else if (s[3]<s[1] && lstto != 3 && (lstfrom != 1 || s[1] == n+1) ) // c to a
				sk[3][s[3]] = 0, sk[1][s[3]] = 1, lstto = 1, lstfrom = 3, printprg(lstto, lstfrom);
			else 
				printf("this should not show %d - %d - %d - %d - %d", s[1], s[2], s[3], lstto, lstfrom), done = 0, lstfrom = 4;

			}
		}
	}
	
}

char int2stck();

void printprg(int to, int from){
	char a,b;
	a = int2stck(from);
	b = int2stck(to);
	printf("\n %c > %c", a, b);
}

char int2stck(int a){
	char z;
	if (a==1)
		z = 'a';
	else if (a==2)
		z = 'b';
	else if (a==3)
		z = 'c';
	return z;
}

int topmost_disc(int stack[]){
	int t1, mx=n+1;
	// n+1 means bigger than anything, suitable for this algo
	for (t1=1; t1<=n; t1++)
		if (stack[t1-1] == 1) {
			mx = t1-1;
			break;
		}
	return mx;
}

// DEBUG
void printStatus(int stack[]){
	int t1;
	printf("\n");
	for (t1=1; t1<=n; t1++){
		if (stack[t1-1] == 1) 
			printf("1 ");
		else printf("0 ");
	}
}