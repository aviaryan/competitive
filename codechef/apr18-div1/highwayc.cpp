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
	ll t,i,j;
	long double n,s,y,time;
 	cin>>t;
 	while(t--)
    {
		cin>>n>>s>>y;
		vector<long double> V(n), D(n), P(n),C(n), I(n);
		rep(i,0,n)
			cin>>V[i];
		rep(i,0,n)
			cin>>D[i];
		rep(i,0,n)
		{			
			cin>>P[i];
			I[i] = P[i];
		}
		rep(i,0,n)
			cin>>C[i];	
				
		time = 0.0;
		rep(i,0,n)
		{
			if(D[i] == 1)
			{
				P[i] = I[i] + (V[i]*time); 				
			}
			else
			{
				P[i] = I[i] - (V[i]*time); 
			}			
			if(P[i] >= 0 && D[i] == 0) 
			{
				if( P[i]/V[i] <= y/s || (P[i] - V[i]*y/s) <= 0.000001)
					time += (P[i]+C[i])/V[i];				
			}
			else if((P[i] < 0 && D[i] == 1))
			{
				if((-1.0*P[i])/V[i] <= y/s || abs(P[i] + V[i]*y/s) <= 0.000001)
					time += (abs(P[i])+C[i])/V[i];
			}
			else if(P[i] >= 0 && D[i] == 1 && P[i] < C[i])
			{
				time += abs(C[i] - P[i])/V[i];
			}
			else if(P[i] < 0 && D[i] == 0 && -1*P[i] < C[i])
			{
				time += (C[i] - abs(P[i]))/V[i];
			}			
			time +=y/s;
		}
		cout<<setprecision(20);
		cout<<time<<"\n";
	}
	return 0;
}	
