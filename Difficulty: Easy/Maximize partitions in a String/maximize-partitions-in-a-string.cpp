//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        // 31.03.25 potd
        int n = s.size();
        unordered_map<char, int> um;
        
        for(int i=0; i<n; i++){
            um[s[i]] = i;
        }
        
        int end = 0, cnt = 0;
        for(int i=0; i<n; i++){
            end = max(end, um[s[i]]);
            if(i == end){
                cnt++;
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends