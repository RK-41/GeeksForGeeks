//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        // 31.07.24 POTD
        string ans, s;
        int minLen=arr[0].length(), n=arr.size();
        
        for(int i=1; i<n; i++){
            int sz = arr[i].size();
            minLen = min(minLen, sz);
        }
        
        for(int i=0; i<minLen; i++){
            int j=0;
            char c=arr[j][i];
            bool valid=true;
            for(j=1; j<n; j++){
                if(arr[j][i] != c){
                    valid = false;
                    break;
                }
            }
            
            if(valid)
                ans += c;
            else
                break;
        }
        
        return ans.size() ? ans : "-1";
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends