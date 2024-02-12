//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long sequence(int n){
        // code here
        // 12.02.24 POTD
        long long ans=0;
        int MOD=1e9+7;
        long long x=1;
        
        for(int i=1; i<=n; i++){
            long long t=1;
            for(int j=1; j<=i; j++){
                t=(t*x)%MOD;
                x++;
            }
            
            ans+=(t%MOD);
        }
        
        return ans%MOD;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends