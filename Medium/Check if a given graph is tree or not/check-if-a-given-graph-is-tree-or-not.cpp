//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
        // code here
        // 24.01.24 potd
        
        vector<int> adjj[n];
        vector<int> vis(n,0);
        queue<pair<int,int>> q;
        
        q.push({0,-1});
        vis[0]=1;
        
        for(auto x: adj){
            adjj[x[0]].push_back(x[1]);
            adjj[x[1]].push_back(x[0]);
        }
        
        while(q.size()){
            auto temp=q.front();
            q.pop();
            
            for(auto it: adjj[temp.first]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it, temp.first});
                } else {
                    if(it != temp.second)
                        return 0;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            if(!vis[i])
                return 0;
        }
        
        return 1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends