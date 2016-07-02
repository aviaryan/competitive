import java.util.*;

public class vishal {
	
	public static long maxSubArray(int[] A) {
		long max_so_far = -10000, max_ending_here = 0;
		
		
		for (int i = 0; i < A.length; i++) {
			max_ending_here = max_ending_here + A[i];
			
			if (max_so_far < max_ending_here) 
				max_so_far = max_ending_here;
			if (max_ending_here < 0)
				max_ending_here = 0;	
		}
		return max_so_far;
	}


	public static long ModSubArray(int[] A) {
		int[] D = new int[A.length];
		long res = 0;
		Boolean neg = false;
//finding indexes with negative numbers
		for(int i=0;i<A.length;i++){
			if(A[i]<0){
				neg = true;
				D[i] = i;
			}
		}

		int[] C = new int[A.length];

		long [] E  = new long[A.length];

		if (neg == false){
			res = maxSubArray(A);

		}
		else{
			//masking negative integers as 0 and finding MaximumSubArraySum
			for(int j=0;j<D.length;j++){
				for(int m=0;m<A.length;m++){
					C[m]=A[m];
				}
				C[D[j]] = 0;
				E[j] = maxSubArray(C);
				long  largest = E[0];
				for(int k =0; k<E.length; k++){
					if(E[k]>largest)
						largest = E[k];
				}	
				res = largest;	
			}}
			return res;
		}
		public static void main(String args[]){
			Scanner s = new Scanner(System.in);
			int i,j,c;
			Boolean flag = false;
			int T = s.nextInt();
			for(c=0;c<T;c++){
				int N = s.nextInt();
				int [] A = new int[N];
				for(i=0;i<N;i++){
					A[i] = s.nextInt();
					if(A[i]>0)
					{
						flag = true;
					}

					
					
		// int largest = A[0];
		// for(int k =0; k<A.length; k++){
		// 	if(A[k]>largest)
		// 		largest = A[k];

				}if(flag == false){
			//System.out.println(largest);
					System.out.println(maxSubArray(A));
				}
				else {
					long r = ModSubArray(A);
					System.out.println(r);
				}
			}
			
		}
	}
	
	