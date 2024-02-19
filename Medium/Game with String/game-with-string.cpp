//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        // 19.02.24 POTD
        if(k >= s.size())   return 0;
        
        int ans=0;
        priority_queue<int> q;
        unordered_map<char,int> count;
        
        for(auto c: s){
            count[c]++;
        }
        
        for(auto p: count){
            q.push(p.second);
        }
        
        while(k--){
            int t=q.top();
            q.pop();
            
            q.push(t-1);
        }
        
        while(q.size()){
            int t=q.top();
            q.pop();
            ans += (t*t);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends