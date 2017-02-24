#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

int board[100], minsteps, boardregions[100];

void slminSteps(int cp, int steps){
	if (cp==99){
		if (steps<minsteps)
			minsteps = steps;
		return;
	}
	if (steps>minsteps || cp>99)
		return;
	int i;
	if (boardregions[cp]-cp > 6)
		slminSteps(cp+6, steps+1);
	else
		for (i=6; i>0; i--)
			if (board[cp+i] >= 0)
				slminSteps( cp+i + board[cp+i], steps+1 );
}

int main(){
	int t, nl, ns, temp;
	char ch;
	scanf("%d", &t);

	int i,a,b;
	for (;t>0;t--){
		minsteps = 10000;
		for (i=0; i<100; i++)
			board[i] = 0;
		scanf("%d%c%d", &nl, &ch, &ns);
		for (i=0; i<nl; i++){
			scanf("%d%c%d", &a, &ch, &b);
			board[a-1] = b-a; 
		}
		for (i=0; i<ns; i++){
			scanf("%d%c%d", &a, &ch, &b);
			board[a-1] = b-a;
		}
		temp = -1;
		for (i=99; i>=0; i--){ // for fast-forwarding the board
			if (board[i] != 0)
				boardregions[i] = temp, temp=i;
			else
				boardregions[i] = temp;
		}

		slminSteps(0, 0);
		printf("%d\n", minsteps);
	}
	return 0;
}