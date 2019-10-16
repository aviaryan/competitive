#include <bits/stdc++.h>
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
//logarithmic expo
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
ll spf[1000001];
bool prime[1000001];

void genprime()
{	   
	int i,j;
    rep(i,0,1000001)
    	prime[i] = true;
    prime[0] = prime[1] ;
    for(i = 2;i<1000001;i++)
    {
    	if(prime[i])
    	{
    		for(j = 2*i;j<1000001;j+=i)
    		{
    			prime[j] = false;
    		}
    	}
    }
}

void genspf()
{
	 spf[1] = 1;int i,j;
     for ( i=2; i<1000001; i++)
         spf[i] = i; 
   
     for ( i=4; i<1000001; i+=2)
        spf[i] = 2;
 
    for ( i=3; i*i<1000001; i++)
    {
        if (spf[i] == i)
        {
            for ( j=i*i; j<1000001; j+=i)
 			{
                if (spf[j]==j)
                    spf[j] = i;
            }
        }
    }
    /*for(i=1;i<100;i++)
    	cout<<spf[i]<<" ";*/
}

vector<ll> factorise(ll n)
{
	vector<ll> ret,ret1;
	while(n!=1)
	{
		ret.push_back(spf[n]);
		n/=spf[n];
	}
	ret1.push_back(ret[0]);
	rep(i,1,ret.size())
	{
		if(ret[i] != ret[i-1])
			ret1.push_back(ret[i]);
	}
	return ret1;
}

int main() {
    ll t,n,i,j,k,m;
   	cin>>n>>m>>k;
    	ll A[n], P[m];
    	rep(i,0,n)
    	{
    	    cin>>A[i];
    	}
    	rep(i,0,m)
    	{
    	    cin>>P[i];
    	}
    	rep(i,0,n)
    	{
    	    cout<<A[i]+k<<" ";
    	}
    	
 	
	return 0;
}
