#include "bits/stdc++.h"
using namespace std;

# define s(n)                        scanf("%d",&n)
# define sc(n)                       scanf("%c",&n)
# define sl(n)                       scanf("%lld",&n)
# define sf(n)                       scanf("%lf",&n)
# define ss(n)                       scanf("%s",n)

#define R(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)

# define INF                         (int)1e9
# define EPS                         1e-9
# define MOD 1000000007


typedef long long ll;

int fact[] ={1,1,2,6,24,120,720,5040,40320,362880,3628800};
int solution(int N) {
   // write your code in C++14 (g++ 6.2.0)
    int freq[11], m=N,leng=0;
    fill_n(freq,11,0);

    float ans=0.0, zero_beg=0;
    if(N==0){  // base case
        return 1;
    }
    while(m>0){            // counting frequencies
        leng++;
        freq[m%10]++;
        m/=10;
    }
    if(leng==1)
        return 1;
    
    ans= fact[leng];
    // cout << ans << endl;
    for(int i=0;i<11;i++){
        ans/=fact[freq[i]];
    }
    // cout << ans << endl;
    
    if (freq[0] > 0) {
        zero_beg= fact[leng-1];
        for(int i=1;i<10;i++){
            zero_beg/=fact[freq[i]];
        }
        ans-=zero_beg/fact[freq[0]-1];
    }
    
    // cout << ans << endl;

return (int) nearbyint(ans);
}

int main()
{
  int t=12;
  int n;
  while(t--){
      s(n);
      printf("%d\n",solution(n));
  }
  
    
    return 0;
}