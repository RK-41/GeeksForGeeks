//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
private:
    vector<int> X = {-1,0,1};
    vector<int> Y = {0,1,0};
    
    bool isBoundary(int i, int j, int n, int m){
        return (i>=0 && j>=0 && i<n && j<m);
    }
    
public:
    int findShortestPath(vector<vector<int>> &mat)
    {
       // code here
       // 27.03.24 Potd
        int r=mat.size(), c=mat[0].size();
        vector<vector<int>> dp(r, vector<int>(c, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
    
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(mat[i][j] == 0){
                    if(i>0)
                        mat[i-1][j] = -1;
                    if(i<r-1)
                        mat[i+1][j] = -1;
                    if(j>0)
                        mat[i][j-1] = -1;
                    if(j<c-1)
                        mat[i][j+1] = -1;
                }
            }   
        }
        
        for(int i=0; i<r; i++)
            if(mat[i][0]==1)
                q.push({1,{i,0}});
                
        while(q.size()){
            auto curr = q.top();
            q.pop();
            
            int steps = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            
            if(j==c-1)
                return steps;
                
            for(int k=0; k<3; k++){
                int newX = i + X[k];
                int newY = j + Y[k];
                
                if(isBoundary(newX, newY, r, c) && mat[newX][newY]==1 && dp[newX][newY]>steps+1){
                    q.push({steps+1, {newX,newY}});
                    dp[newX][newY] = steps+1;
                }
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> mat(R, vector<int>(C));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> mat[i][j];
            }
        }

        Solution ob;
        int ans = ob.findShortestPath(mat);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends