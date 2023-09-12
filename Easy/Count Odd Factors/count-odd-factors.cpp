//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int count(int N){
        // code here
        // 12.09.23
        // OBSERVATION: Perfect squares have odd no. of factors
        
        if(N==1)    return 1;
        
        int ans = 1;
        for(int i=2; i<=N; i++){
            int sqt = sqrt(i);
            if(sqt*sqt == i)
                ans++;
        }
        
        return ans;
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
        cout << ob.count(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends