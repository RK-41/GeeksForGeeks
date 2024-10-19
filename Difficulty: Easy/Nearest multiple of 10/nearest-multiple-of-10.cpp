//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        // Complete the function
        // 19.10.24 POTD
        string ans = str;
        char ch = ans.back();
        int n = str.size()-2;
        
        ans.pop_back();
        ans.push_back('0');
        
        if(ch > '5'){
            int carry = 1;
            while(n>=0){
                if(ans[n] < '9'){
                    ans[n]++;
                    carry = 0;
                    break;
                } else {
                    ans[n] = '0';
                }
                n--;
            }
            if(carry){
                ans = "10" + ans.substr(1);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends