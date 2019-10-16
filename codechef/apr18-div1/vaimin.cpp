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

int main() {
    ll t,n,p,q,c,i,j,k,m,g,b,flag=0;
    set<pair<ll, ll> > myset;
   	cin>>p>>q>>c>>m;
    //p = 15; q = 15;m=0;c=0;
    rep(i,0,m)
	{
	    cin>>g>>b;
	    if(g<c && b==0)
	    {
	    	flag=1;
	    }
	    myset.insert(make_pair(g,b));
	} 
	
    if(p-c < q || (p == 0 && q == 0 && c==0) || flag == 1)
    {
    	cout<<"0\n";
    	return 0;
    }
    
    ll A[p-c+1][q+1];
        
    rep(i,0,p-c+1)
    {
        rep(j,i+1,q+1)
        {
            A[i][j] = 0;
        }
    }
      
    flag = 0;
	rep(i,0,p-c+1)
	{
		if(flag == 1)
		{
			A[i][0] = 0;
		}
		else
		{
			if(myset.find(make_pair(i+c,0))==myset.end())
		    {
		        A[i][0] = 1;
		    }
		    else
		    {		    	
		    	flag = 1;
				A[i][0] = 0;
			}
	    }
	}	
	
    rep(i,1,p-c+1)
    {
        rep(j,1,min(ll(i+1),q+1))
        {
            if(myset.find(make_pair(i+c,j))==myset.end())
            {
                A[i][j] = (A[i-1][j]+A[i][j-1])%mod;
            }
            else
            	 A[i][j] = 0;
        }
    }
   /* 
    rep(i,0,p-c+1)
    {
        rep(j,0,q+1)
        {
            cout<<A[i][j]<<" ";
        }
        cout<<"\n";
    }
  */
 	cout<<A[p-c][q]<<"\n";
	return 0;
}
