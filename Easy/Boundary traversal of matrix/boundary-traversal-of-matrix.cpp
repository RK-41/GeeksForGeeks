//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        // code here
        // 01.10.23 POTD
        
        vector<int> bt;
    
        if(n==1 || m==1){
            for(auto &r:matrix){
                for(auto e:r){
                    bt.push_back(e);
                }
            }
            
            return bt;
        }
        
        for(int j=0; j<m-1; j++)    bt.push_back(matrix[0][j]);
        for(int i=0; i<n-1; i++)    bt.push_back(matrix[i][m-1]);
        for(int j=m-1; j>0; j--)    bt.push_back(matrix[n-1][j]);
        for(int i=n-1; i>0; i--)    bt.push_back(matrix[i][0]);
        
        return bt;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(m, 0);
            for( int j=0; j<m; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.boundaryTraversal(matrix, n, m);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends