//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int min_sprinklers(int gallery[], int n)
    {
        // code here
        // 18.01.24 (POTD)
        vector<int> v(n+1,0);
        for(int i=0; i<n; i++){
            if(gallery[i]==-1)  continue;
            
            if(v[i] < i+gallery[i]){
                int left=i-gallery[i];
                int right=i+gallery[i];
                
                while(left<=right){
                    if(left>=0 && left<n){
                        v[left]=right;
                    }
                    left++;
                }
            }
        }
        
        int end=0, cnt=0;
        while(end<n){
            if(v[end]==0) return -1;
            
            end=v[end];
            cnt++;
            end++;
        }
        
        return cnt;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        int gallery[n];
        for(int i=0; i<n; i++)
            cin>> gallery[i];
        Solution obj;
        cout<< obj.min_sprinklers(gallery,n) << endl;
    }
	return 1;
}

// } Driver Code Ends