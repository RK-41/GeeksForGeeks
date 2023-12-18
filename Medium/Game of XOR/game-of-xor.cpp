//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int gameOfXor(int N , int A[]) {
        // code here
        // 18.12.23 potd
        
        int xr=0, prev=0, curr=0;
        
        for(int i=0; i<N; i++){
            prev = curr;
            curr = N+prev-2*i;
            
            if(curr%2 != 0)
                xr ^= A[i];
        }
        
        return xr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        for(int i=0 ; i<N ; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.gameOfXor(N,A) << endl;
    }
    return 0;
}
// } Driver Code Ends