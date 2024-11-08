//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minRepeats(string& s1, string& s2) {
        // code here
        // 08.11.24
        int ans = 1;
        unordered_set<char> st = {s1.begin(), s1.end()};
        
        for(auto c: s2){
            if(!st.count(c))
                return -1;
        }
        
        string s = s1;
        while(s.size() < s2.size()){
            s += s1;
            ans++;
        }
        
        int count = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == s2[0]){
                if(s.size()-i < s2.size()){
                    s += s1;
                    ans++;
                    count++;
                }
                if(s.substr(i,s2.size()) == s2){
                    break;
                }
                
                if(count == 3)  return -1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string A, B;
        getline(cin, A);
        getline(cin, B);

        Solution ob;
        cout << ob.minRepeats(A, B) << endl;
    }
    return 0;
}
// } Driver Code Ends