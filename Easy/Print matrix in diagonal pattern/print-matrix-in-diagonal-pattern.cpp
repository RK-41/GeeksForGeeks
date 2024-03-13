//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         // 13.03.24 potd
        vector<int> ans;
        int n=mat.size();
        int diag = 0;
        
        while(diag < 2*n-1){
            if(diag & 1){
                int r=0, c=diag;
                while(r<n && c>=0){
                    if(c<n) 
                        ans.push_back(mat[r][c]);
                    r++, c--;
                }
            } else {
                int r=diag, c=0;
                while(r>=0 && c<n){
                    if(r<n) 
                        ans.push_back(mat[r][c]);
                    r--, c++;
                }
            }
            
            diag++;
        }
        
        return ans;
        
        
        // int i=0, j=0, n=mat.size();
        // bool right=true, downleft=false, down=false, upright=false;
         
        // ans.push_back(mat[0][0]);
        
        // while(i<n && j<n){
        //     if(right){
        //         j++;
        //         right = false;
        //         downleft = true;
        //     } else if(downleft){
        //         i++, j--;
                
        //         if(i+1 == n || j-1 < 0){
        //             downleft = false;
        //             down = true;
        //         }
        //     } else if(upright){
        //         i--, j++;
                
        //         if(i-1 < 0 || j+1 == n){
        //             upright = false;
        //             down = true;
        //         }
        //     } else if(down){
        //         i++;
        //         down = false;
        //         downleft = true;
        //     }
            
        //     // cout<<mat[i][j]<<" ";
        //     ans.push_back(mat[i][j]);
        // }
        
        // return ans;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends