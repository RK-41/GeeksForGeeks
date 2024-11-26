//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {
        // your code here
        // 26.11.24 potd
        int n = arr.size();
        int sum = accumulate(arr.begin(),arr.end(),0);
        int ans = INT_MIN;
        int currentsum = 0;

        
        for(int i = 0; i<n; i++)
        {
            currentsum += arr[i];
            ans = max(ans, currentsum);
            if(currentsum<0) currentsum = 0;
        }
        int frontmax = arr[0];
        int frontsum = arr[0];
        for(int i = 1; i<n; i++)
        {
            sum -= arr[i-1];
            if(frontmax>0)
            {
                int maxi = sum + frontmax;
                ans = max(ans,maxi);
                
            }
            frontsum += arr[i];
            frontmax = max(frontmax,frontsum);
            
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends