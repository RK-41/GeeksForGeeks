//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            // 20.09.23 potd
            
            int nn=n;
            d%=16;
            
            // rotating towards left
            nn = (((n<<d) | (n>>(16-d))) & 65535);
            
            // rotating towards right
            n = (((n>>d) | (n<<(16-d))) & 65535);
            
            return {nn,n};
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        
        int n, d; cin >> n >> d;
        Solution ob;
        vector <int> res = ob.rotate (n, d);
        cout << res[0] << endl << res[1] << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends