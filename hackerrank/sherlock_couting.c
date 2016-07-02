#include <stdio.h>
#include <math.h>

main(){
	int t, ans;
	scanf("%d", &t);
	unsigned long long nk, nimx, n, k;
	double dn, dk, x1,x2;
	int ix1, ix2;

	for (;t>0;t--){
		scanf("%llu %llu", &n, &k);
		nk = n*k;
		nimx = n/2;
		nimx *= (n-nimx);
		ans = 0;

		if (nk >= nimx){ // all sols as max of n*i is less than nk
			ans = n-1;
		} else {
			// quad calc roots
			// no imag root here as that is dealt by if above
			dn = (double) n, dk = (double) nk;
			x1 = ( -dn + sqrt( dn*dn - 4*dk ) ) / -2.0;
			x2 = ( -dn - sqrt( dn*dn - 4*dk ) ) / -2.0;
			ix1 = x1; // works as floor
			ix2 = ceil(x2);
			ans = ix1 + (n-ix2);
		}

		printf("%d\n", ans);
	}
}