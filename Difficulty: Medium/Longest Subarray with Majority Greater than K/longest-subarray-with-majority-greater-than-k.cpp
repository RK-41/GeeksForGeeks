//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int longestSubarray(vector<int> &arr, int k) {
        // Code here
        // 10.05.25 potd
        int ans = 0, cnt = 0;
        unordered_map<int,int> um;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= k) cnt--;
            else            cnt++;
            
            if(cnt > 0)
                ans = max(ans, i + 1);
            
            int y = cnt - 1;
            if(um.find(y) != um.end())
                ans = max(ans, i - um[y]);
            
            if(um.find(cnt) == um.end())
                um[cnt] = i;
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
        getline(cin, input);
        int k = stoi(input);

        Solution ob;
        cout << ob.longestSubarray(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends