//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        // 18.08.24 POTD
        int totalSum = accumulate(arr.begin(), arr.end(), 0);
        if(totalSum%2 == 1)
            return false;
            
        int sum = 0, halfSum = totalSum/2, n = arr.size();
        
        for(int i=0; i<n-1; i++){
            sum += arr[i];
            
            if(halfSum == sum)
                return true;
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t-- > 0) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }

        Solution obj;
        bool res = obj.canSplit(arr);
        cout << (res ? "true" : "false") << endl;
    }
    return 0;
}
// } Driver Code Ends