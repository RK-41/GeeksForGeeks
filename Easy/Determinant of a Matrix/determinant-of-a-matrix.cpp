//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > mat, int n)
    {
        // code here 
        // 25.12.23 (potd)
        if(n==1)
            return mat[0][0];
            
        if(n==2)
            return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];
            
        int ans=0;
        for(int i=0; i<n; i++){
            vector<vector<int>> temp;
            for(int j=1; j<n; j++){
                vector<int> v;
                for(int k=0; k<n; k++){
                    if(k==i)    continue;
                    
                    v.push_back(mat[j][k]);
                }
                temp.push_back(v);
            }
            if(i&1)
                ans -= mat[0][i]*determinantOfMatrix(temp,n-1);
            else
                ans += mat[0][i]*determinantOfMatrix(temp,n-1);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends