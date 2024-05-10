//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        // 10.05.24 potd
        vector<vector<int>> ans;
        vector<int> path;
        long long sum=0;
        
        sort(arr.begin(), arr.end());
        helper(ans, arr, path, 0, sum, k);
        
        return ans;
    }
    
    void helper(vector<vector<int>> &ans, vector<int> &arr, vector<int> &path, int idx, long long sum, int k){
        if(sum >= k){
            if(sum == k){
                ans.push_back(path);
            }
            return;
        }
        
        if(idx >= arr.size()){
            return;
        }
        
        path.push_back(arr[idx]);
        helper(ans, arr, path, idx+1, sum+arr[idx], k);
        path.pop_back();
        
        while(idx+1 < arr.size() && arr[idx] == arr[idx+1]){
            idx++;
        }
        
        helper(ans, arr, path, idx+1, sum, k);
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
        vector<int> arr(n);
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        auto obj=ob.CombinationSum2(arr,n,k);
        for(int i=0;i<obj.size();i++)
        {
            for(int j=0;j<obj[i].size();j++)
            {
                cout<<obj[i][j]<<" ";
            }
            cout<<"\n";
        }
        if(obj.size()==0) cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends