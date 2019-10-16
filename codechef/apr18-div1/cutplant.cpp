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
//seg tree rmax, rmin
struct node
{
   ll minimum;
   ll maximum;
};

ll getMid(ll s, ll e) {  return s + (e -s)/2;  }

struct node MaxMinUntill(struct node *st, ll ss, ll se, ll qs,
                         ll qe, ll index)
{
    // If segment of this node is a part of given range, then return
    //  the minimum and maximum node of the segment
    struct node tmp,left,right;
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
    {
       tmp.minimum = INT_MAX;
       tmp.maximum = INT_MIN;
       return tmp;
     }
 
    // If a part of this segment overlaps with the given range
    ll mid = getMid(ss, se);
    left = MaxMinUntill(st, ss, mid, qs, qe, 2*index+1);
    right = MaxMinUntill(st, mid+1, se, qs, qe, 2*index+2);
    tmp.minimum = min(left.minimum, right.minimum);
    tmp.maximum = max(left.maximum, right.maximum);
    return tmp;
}
 
struct node MaxMin(struct node *st, ll n, ll qs, ll qe)
{
    struct node tmp;
    if (qs < 0 || qe > n-1 || qs > qe)   {       
        tmp.minimum = INT_MIN;
        tmp.minimum = INT_MAX;
        return tmp;
    } 
    return MaxMinUntill(st, 0, n-1, qs, qe, 0);
}

void constructSTUtil(ll arr[], ll ss, ll se, struct node *st,
                     ll si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si].minimum = arr[ss];
        st[si].maximum = arr[ss];
        return ;
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the minimum and maximum of two values
    // in this node
    ll mid = getMid(ss, se);
    constructSTUtil(arr, ss, mid, st, si*2+1);
    constructSTUtil(arr, mid+1, se, st, si*2+2);
 
    st[si].minimum = min(st[si*2+1].minimum, st[si*2+2].minimum);
    st[si].maximum = max(st[si*2+1].maximum, st[si*2+2].maximum);
}
struct node *constructST(ll arr[], ll n)
{
    // Allocate memory for segment tree 
    // Height of segment tree
    ll x = (ll)(ceil(log2(n)));
 
    // Maximum size of segment tree
    ll max_size = 2*(ll)pow(2, x) - 1;
 
    struct node *st = new struct node[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}

int main()
{
	ll t,n,j,i,ctr,flag,mx,mi;
	cin>>t;
	
	while(t--)
	{
		ctr=flag =0;
		cin>>n;
		ll A[n], B[n];
		bool alive[n];
		unordered_map <ll, queue<ll> > mymap;
		
		rep(i,0,n)
		{
			cin>>A[i];
		}
		rep(i,0,n)
		{
			cin>>B[i];
			if(B[i] > A[i])
				flag = 1;
			if(B[i]!=A[i])
				mymap[B[i]].push(i);
		}
		if(flag == 1)
		{
			cout<<"-1\n";
			continue;
		}
		i=0;
		while(i<n)
		{
			if(A[i]>B[i])
			{
				flag = 1;
				break;
			}
			i++;
		}		
		if(flag == 0)
		{
			cout<<"0\n";
			continue;
		}
		// kaam ka
		
		struct node *stA = constructST(A, n),*stB = constructST(B, n);;
 
		int qs = 2;  // Starting index of query range
		int qe = 6;  // Ending index of query range
		struct node result=MaxMin(stA, n, qs, qe);
		
		//cout<<result.minimum<<" "<<result.maximum<<"\n";
		 
		 qs = 1;  // Starting index of query range
		 qe = 5;  // Ending index of query range
		  result=MaxMin(stB, n, qs, qe);
		//cout<<result.minimum<<" "<<result.maximum<<"\n";
		
		
		rep(i,0,n)
		{
			if(A[i] ==B[i])
				alive[i] = false;
			else
				alive[i] =true;
		}
		rep(i,0,n)
		{
			if(alive[i])
			{
				//cout<<B[i]<<" -> ";
				
				if(mymap[B[i]].size() == 1)
				{
					ctr++;
					continue;
				}
				//cout<<B[i]<<" -> ";
				while(!mymap[B[i]].empty())
				{
					qs = mymap[B[i]].front();
					mymap[B[i]].pop();
					if(mymap[B[i]].empty())
						break;
					qe = mymap[B[i]].front();
					
					//cout<<qs<<" "<<qe<<" gives ";
					
					mx = MaxMin(stB, n, qs, qe).maximum;										
					mi = MaxMin(stA, n, qs, qe).minimum;
					
					if(mx <= B[i] && mi >= B[i])
					{
						alive[qe] = false;
						//cout<<"false\n";
					}
					else
					{
						//cout<<"break\n";
						break;
						
					}
				}
				/*
				rep(j,i+1,n)
				{
					//cout<<B[j]<<" "<<A[j]<<"\n";
					if(B[j]>B[i] || A[j]<B[i])
						break;
					else if(B[j] == B[i])
					{
						alive[j] = false;
					}
				}*/
				ctr++;
			}
			//cout<<ctr<<" ";			
		}
		cout<<ctr<<"\n";	
	}	
	return 0;
}	
