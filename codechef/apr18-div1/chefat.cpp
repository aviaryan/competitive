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
    ll t,n,q,i,j,l,r,type;
   	cin>>n>>q;
    
    double P[q],ans,T;
    rep(i,0,n)
    {
    	cin>>P[i];
    }
    cout<<setprecision(8);
    while(q--)
    {
    	ans = 1.0;
    	cin>>type;
    	if(type == 0)
    	{
    	   	cin>>l>>r;
    		rep(i,l-1,r)
    			ans *= (1-P[i]);
			cout<<ans<<"\n";
		}
		else
		{
			cin>>l>>r>>T;
			rep(i,l-1,r)
    			P[i] *= T;
		}
    }
    
   
	return 0;
}
