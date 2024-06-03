//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
        // 03.06.24 potd
        if(n < 2)   return 0;
        if(n == 2)  return 1;
        
        int mod=1e9+7, zeroOnes=1, onlyOnes=2, power=2;
        
        for(int i=3; i<n; i++){
            int t = (zeroOnes + onlyOnes)%mod;
            power = (power*2)%mod;
            onlyOnes = (power + zeroOnes)%mod;
            zeroOnes = t;
        }
        
        return (zeroOnes + onlyOnes)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends