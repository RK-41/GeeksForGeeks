//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
#define mod 1000000007
class Solution{
public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        // code here
        // 24.11.23 POTD
        if(n==1)    return {1};
        if(n==2)    return {1,1};
        
        vector<long long> ans(2);
        long long ele = 1;
        ans[0] = ans[1] = ele;
        
        for(int i=3; i<=n; i++){
            vector<long long> v(i);
            v[0] = 1;
            
            for(int j=1; j<ans.size(); j++){
                v[j] = (ans[j]+ans[j-1])%mod;
            }
            
            v[i-1] = 1;
            ans = v;
        }
        
        return ans;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends