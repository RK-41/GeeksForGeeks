//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        // code here
        // 26.07.24 POTD
        if(str.size() < 26) return false;
        
        unordered_map<char,int> fr;
        int count = 0;
        
        for(auto c: str){
            if(c != ' '){
                fr[c]++;
                count++;            
            }
        }
        
        if(count < 26 || fr.size() + k < 26)  return false;
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends