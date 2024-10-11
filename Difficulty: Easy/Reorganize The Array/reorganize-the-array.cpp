//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        // Code here
        // 11.10.24 POTD
        vector<int> ans = arr;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            if(ans[i] == -1 || ans[i] == i)    
                continue;
                
            swap(ans[ans[i]], ans[i]);
        }
        
        for(int i=0; i<n; i++){
            if(ans[i] == -1 || ans[i] == i)    
                continue;
                
            swap(ans[ans[i]], ans[i]);
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
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends