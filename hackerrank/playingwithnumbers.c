#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct item
{
	long long count;
	long long pos;
};

long long absl(long long n){
	// that returns int, wtf
	return (n<0) ? -n : n;
}

int main() {
	int n;
	scanf("%d", &n);
	int i, j;
	struct item nums[4001];
	long long sp, cp, msum, mcount, cp_ind, term;

	for (i=0; i<4001; i++){
		nums[i].count = 0;
		nums[i].pos = i-2000;
	}

	for (i=0; i<n; i++){
		scanf("%lld", &term);
		nums[term+2000].count++;
	}

	struct item negs[2001]; // -2001 .. -1
	negs[0].count = 0;
	negs[0].pos = 0;
	for (i=1; i<2001; i++){
		negs[i].pos = nums[2000-i].count * nums[2000-i].pos + negs[i-1].pos;
		negs[i].count = nums[2000-i].count + negs[i-1].count;
	}

	struct item pos[2001];
	pos[0].count = nums[0+2000].count;
	pos[0].pos = nums[0+2000].pos;
	for (i=1; i<2001; i++){
		pos[i].pos = nums[i+2000].count * nums[i+2000].pos + pos[i-1].pos;
		pos[i].count = nums[i+2000].count + pos[i-1].count;
	}

	int q;
	scanf("%d", &q);
	cp = 0;

	for (j=0; j<q; j++){
		scanf("%lld", &term);
		cp -= term; // inverse
		sp = 0;
		if (cp <= 0){
			cp_ind = (cp<(-2000)) ? 2000 : -cp;
			msum = negs[cp_ind].pos;
			mcount = negs[cp_ind].count;
			sp += absl( negs[2000].pos-negs[cp_ind].pos + (negs[2000].count-negs[cp_ind].count) * (-cp) );
			sp += absl( msum + mcount * (-cp) );
			sp += pos[2000].pos + pos[2000].count * (-cp);
		} else {
			cp_ind = (cp>2000) ? 2000 : cp;
			msum = pos[cp_ind].pos;
			mcount = pos[cp_ind].count;
			sp += absl( pos[2000].pos-pos[cp_ind].pos + (pos[2000].count-pos[cp_ind].count) * (-cp) );
			sp += absl( msum + mcount * (-cp) );
			sp += absl( negs[2000].pos + negs[2000].count * (-cp) );
		}
		printf("%lld\n", sp);
	}

	return 0;
}