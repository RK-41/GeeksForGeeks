//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string s) {
        // Your code here
        // 26.03.24 potd
        int first=0, n=s.size();
        
        for(int i=0; i<n-2; i++){
            first = (first*10) + s[i]-'0';
            int second=0;
            
            for(int j=i+1; j<n-1; j++){
                second = (second*10) + s[j]-'0';
                int n1=first, n2=second;
                int third=0, k=0;
                
                for(k=j+1; k<n; k++){
                    third = (third*10) + s[k]-'0';
                    if(third == (n1+n2)){
                        n1 = n2;
                        n2 = third;
                        third = 0;
                    }
                }
                
                if(k==n && third==0)
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends