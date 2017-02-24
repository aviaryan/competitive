// by harshit
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long m, p;
	    cin>>p>>m;
	    if(m==p)
	    {
	        cout<<"0"<<endl;
	        continue;
	    }
	    long long count=0;
	    while(m!=0 || p!=0)
	    {
	        if(m==0)
	        {
	            if(p%2==1)
	                count++;
	        }
	        else if(p==0)
	        {
	            if(m%2==1)
	                count++;
	        }
	        
	        else if(m%2!=p%2)
	        {
	            count++;
	        }
	        m = m/2;
	        p = p/2;
	    }
	    
	    cout<<count<<endl;
	    
	}
	return 0;
}