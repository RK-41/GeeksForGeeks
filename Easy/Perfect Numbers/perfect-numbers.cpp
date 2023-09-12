//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long N) {
        // code here
        // 12.09.23 POTd
        if(N==1)    return 0;
        
        long long int factorSum = 1;
        
        for(int i=2; i<sqrt(N); i++){
            if(N%i == 0){
                factorSum += i;
                
                if(N/i != N)
                    factorSum += N/i;
            }
        }
        
        return factorSum==N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends