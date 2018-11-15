#include<bits/stdc++.h>
#define lli  long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
using namespace std;
const int mod=1e9+7;
int main()
{
fast;
lli t;
cin>>t;
	while(t--){
		lli n;
		cin>>n;
		lli arr[n+1],c[n+1]={0},i,j;
		bool b[n+1]={false};
		for(i=0;i<n;i++)
		cin>>arr[i],b[arr[i]]=true;
		
		for(i=0;i<n;i++){
			if(b[i+1])
			c[arr[i]]++;
		}
		i=0;
		for(i=1;i<=n;i++){
			if(c[i]>=2){
	            cout<<"Truly Happy\n";
	            break;
		}
		
		if(i>n)
		cout<<"Poor Chef"<<endl;
	
	}
}}

