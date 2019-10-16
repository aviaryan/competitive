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
	ll t,n,i,j,a,b,ans,term,d,len;
	string s;
 	cin>>t;
 	while(t--)
    {
		cin>>s>>n;	
		
		len = s.size();
		ll A[len], B[len];
		vll indices,indices2;
		a=b=ans=0;
		rep(i,0,len)
		{
			if(s[i] == 'a')
				a++;
			else
				b++;
			A[i] = a;
			B[i] = b;
			
			if(A[i]>B[i])
			{	
				ans++;
				indices2.push_back(i);	
			}
			else
				indices.push_back(i);
		}
		
		d = a - b;
		
		if(d>0)
		{
			ans *= n;
			rep(i,0,indices.size())
			{
				//cout<<indices[i]<<"\n";
				a = A[indices[i]] - B[indices[i]];
				term = (-a/d)+1;
				if(term >n)
					term  = 0;
				if(term>0)
					ans += (n-term);	
				//cout<<a<<" "<<d<<" "<<term<<"\n";		
			}
		}
		else if(d<0)
		{
			ans = 0;
			rep(i,0,indices2.size())
			{
				//cout<<indices2[i]<<"\n";
				a = A[indices2[i]] - B[indices2[i]];
				
				if((-1*a)%d == 0)
					term = -a/d;
				else
					term = -a/d+1;
				
				term = min(term,n);				
				ans += term;	
				//cout<<a<<" "<<d<<" "<<term<<"\n";		
			}
		}
		else
			ans *= n;
		cout<<ans<<"\n";		
	}
	
	
	/*end = clock();
	cout<<"\nCPU time used: "<<((double) (end - start)) / CLOCKS_PER_SEC<<" seconds\n";
	*/
	return 0;
}
