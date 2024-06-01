//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        // code here
        // 01.06.24 POTD
        unordered_map<char,int> pos, fr;
        int x=0, y=0;
        
        for(int c=1; c<=26; c++){
            pos[c-1+'a'] = c;
        }
        
        for(char c: s){
            fr[c]++;
        }
        
        for(int i=0; i<s.size(); i++){
            if(fr[s[i]] == 0)   continue;
            
            if(pos[s[i]]%2 == 0){
                if(fr[s[i]]%2 == 0){
                    x++;
                }
            } else {
                if(fr[s[i]]%2 == 1){
                    y++;
                }
            }
            
            fr[s[i]] = 0;
        }
        
        return (x+y)%2 == 1 ? "ODD" : "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends