//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        // 11.02.24 POTD;
        vector<int> ans(n);
        set<int> included;
        
        ans.push_back(0);
        included.insert(0);
        
        for(int i=1; i<n; i++){
            if(ans[i-1]-i > 0 && included.find(ans[i-1]-i) == included.end()){
                ans[i]=ans[i-1]-i;
                included.insert(ans[i-1]-i);
            } else {
                ans[i]=ans[i-1]+i;
                included.insert(ans[i-1]+i);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends