//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int sumOfDigits(int N){
        //code here
        // 16.09.23
        
        vector<int> dp(N+1, 0);
        
        for(int i=1; i<=N; i++)
            dp[i] = i%10 + dp[i/10];
            
        long sum = 0;
        return accumulate(dp.begin(), dp.end(), sum);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.sumOfDigits(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends