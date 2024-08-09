//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Maximize(vector<int> &arr) {
        // Complete the function\
        // 09.08.24 POtd
        long long int ans=0, mod=1e9+7, n=arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(long long int i=0; i<n; i++){
            arr[i] = ((arr[i]%mod) * i)%mod;
            ans = ((ans%mod) + arr[i])%mod;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends