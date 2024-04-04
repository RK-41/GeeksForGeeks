//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        // 04.04.24 potd
        long long ans=0, prev=0, rep=0, n=s.size();
        int MOD=1e9+7;
        
        for(int i=n-1; i>=0; i--){
            long long num = s[i]-'0';
            rep = ((10*rep)%MOD+1)%MOD;
            prev = (prev + (rep*num)%MOD)%MOD;
            ans = (ans + prev)%MOD;
            // cout<<rep<<" "<<prev<<" "<<ans<<endl;
        }
            
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends