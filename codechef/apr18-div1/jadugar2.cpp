#include <bits/stdc++.h>
#include <sstream>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
 
#define rep(i, a, b) \
for (int i = int(a); i < int(b); i++) // a to b, and variable i is local!
#define TRvi(c, it) \
for (vi::iterator it = (c).begin(); it != (c).end(); it++)
#define TRvii(c, it) \
for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define TRmsi(c, it) \
for (msi::iterator it = (c).begin(); it != (c).end(); it++)
#define INF 2000000000 // 2 billion
#define mod 1000000007
 
ll power(ll x, ll y)
{
    ll val=1;    
    x = x%mod;
    while(y>0)
    {
        if(y&1)
        {
            val = (val*x)%mod;
        }
        y = y>>1;
        x = (x*x)%mod;
    }
    return val;
}
 
int main()
{
	/*clock_t start,end;
	start  = clock();*/
	ll t,d,n,i,j,K,A,B,q,l,r,ans,a,b,Asq, c;
 
	cin>>n>>K>>A>>B;
	
	vll dp(n+1),sum(n+1);
	//ll s=0;
	dp[1] = K;
	sum[1] =(power(K,2))%mod;
	dp[2] = (((A%mod)*(K%mod))%mod + ((B%mod)*power(K,2))%mod)%mod;
	//cout<<sum[0]<<" ";
	c = (A+(((2*K%mod)*(B%mod))%mod))%mod;
	Asq = power(A,2);
	//cout<<dp[1]<<" "<<dp[2]<<" ";
	
	sum[2] = (sum[1]+(power(dp[2],2))%mod)%mod;
	//cout<<sum[1]<<" "<<sum[2]<<" ";
	rep(i,3,n+1)
	{
		//dp[i] = (((A+(2*((K%mod)*(B%mod))%mod)%mod)%mod)*((2*i-3)*(dp[i-1]))%mod)%mod;
		
		a = ((((2*i-3)*(dp[i-1]%mod))%mod)*(c)%mod);
		b = (((Asq*(i-3))%mod)*dp[i-2])%mod;
			
		if(a-b >=0)
			dp[i] = a-b;
		else
			dp[i] = a-b+mod;
		
		dp[i] = (power(i,mod-2)*dp[i])%mod;
	
		//cout<<dp[i]<<" ";
		//dp[i] = ((((4*i-2)*(dp[i-1]%mod))%mod)*(((K%mod)*(B%mod))%mod))%mod;
		//dp[i] = (power(i+1,mod-2)*dp[i])%mod;
		sum[i] = (sum[i-1] + power(dp[i],2)%mod)%mod;
		//cout<<sum[i]<<" ";
	}
	
	//cout<<dp[n];
	
	cin>>q; 
	while(q--)
	{
		cin>>l>>r;
		ans =0;
		
		if(l == 1)
		{
			ans = sum[r];	
		}
		else
		{
			ans = (sum[r] - sum[l-1])%mod;
		}
		if(ans <0)
			ans+=mod;
		cout<<ans%mod<<"\n";
	}
	
	
	/*end = clock();	
	cout<<"\nCPU time used: "<<((double) (end - start)) / CLOCKS_PER_SEC<<" seconds\n";
	*/
	
	
	return 0;
}
