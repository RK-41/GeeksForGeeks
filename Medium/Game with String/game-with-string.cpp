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
        
        // Counting each character's frequency
        for(auto c: s){
            count[c]++;
        }
        
        // Storing the frequency count in a priority so that 
        //  frequencie counts from higher end will be easily accessible
        for(auto p: count){
            q.push(p.second);
        }
        
        // Taking the highest frequency count 't', 
        //  and pushing the updated frequency count 't-1'
        // This operation is done 'k' times
        while(k--){
            int t=q.top();
            q.pop();
            
            q.push(t-1);
        }
        
        // Remaining queue elements are the frequency counts after removal of 'k' character,
        //  which are used to calculate the required sum
        while(q.size()){
            int t=q.top();
            q.pop();
            
            ans += (t*t);
        }
        
        // Returning the required sum
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