//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    long long sumOfDivisors(int N)
    {
        // Write Your Code here
        // Observation: Every integer i in the range 1 to N appears N/i times 
        // in the ans(ie, factor-sum)
        
        long long factorSum = 0;
        
        for(int i=1; i<=N; i++){
            factorSum += i * (N/i);
        }
        
        return factorSum;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        Solution ob;
        long long ans  = ob.sumOfDivisors(N);
        cout<<ans<<endl;
    }
    return 0;
}
// } Driver Code Ends