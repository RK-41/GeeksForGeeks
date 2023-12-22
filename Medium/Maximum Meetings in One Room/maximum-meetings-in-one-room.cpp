//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        // 22.12.23 potd
        vector<int> ans;
        vector<pair<int,int>> ff;
        int last;
        
        for(int i=0; i<N; i++){
            ff.push_back(make_pair(F[i], i+1));
        }
        
        sort(ff.begin(), ff.end());
        ans.push_back(ff[0].second);
        last = ff[0].first;
        
        for(int i=1; i<N; i++){
            if(S[ff[i].second-1] > last){
                ans.push_back(ff[i].second);
                last = ff[i].first;
            }
        }
        
        sort(ans.begin(), ans.end());
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
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends