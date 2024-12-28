//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        // 28.12.24 (POTD)
        vector<vector<int>> ans;
        int n = arr.size();
        
        for(int i=0; i<n; i++){
            unordered_map<int,vector<int>> pos;
            
            for(int j=i+1; j<n; j++){
                int x = -(arr[i] + arr[j]);
                
                if(pos.count(x)){
                    vector<int> v = pos[x];
                    
                    for(auto p: v){
                        ans.push_back({i,p,j});
                    }
                }
                
                pos[arr[j]].push_back(j);
            }
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends