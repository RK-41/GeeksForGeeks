//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        // code here
        // 06.08.24 POTD
        int dots = 3, num = 0;
        
        for(int i=0; i<str.size(); i++){
            if(str[i] != '.'){
                num = num*10 + str[i] - '0';
                
                if(num == 0 && i<str.size()-1 && str[i+1] != '.')
                    return 0;
            } else if(dots >= 0){
                if(num < 0 || num > 255 || (i>0 && str[i-1] == '.'))
                    return 0;
                
                num = 0;
                dots--;
            } else {
                return 0;
            }
        }
        
        return dots == 0 && num <= 255;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends