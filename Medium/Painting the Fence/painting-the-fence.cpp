//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        // 14.12.23 potd
        
        if(n==1)    return k;
        
        long mod=(long) 1e9+7, same=0, diff=k, total=same+diff;
        
        for(int i=2; i<=n; i++){
            long temp=diff;
            diff=(total*(k-1))%mod;
            same=temp;
            total=(same+diff)%mod;
        }
        
        return (total)%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends