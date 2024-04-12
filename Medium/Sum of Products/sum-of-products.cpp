//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        // 12.04.24 potd
        long long ans=0;
        
        for(int i=0; i<32; i++){
            int cnt=0;
            for(int j=0; j<n; j++)
                if(arr[j] & (1<<i))
                    cnt++;
                    
            ans += (1LL<<i)*(cnt)*(cnt-1)/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends