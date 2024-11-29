//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        // 29.11.24 POTD
        string ans, a, b;
        
        int j=0;
        while(s1[j] == '0'){
            j++;
        }
        a = s1.substr(j);
        
        j=0;
        while(s2[j] == '0'){
            j++;
        }
        b = s2.substr(j);
        
        int m=a.size(), n=b.size();
        int i=0, mx=max(m,n);
        int carry=0, sum=0;
        
        while(i<mx){
            sum = carry;
            carry = 0;
            
            if(i<m){
                sum += a[m-1-i]-'0';
            }
            if(i<n){
                sum += b[n-1-i]-'0';
            }
            
            if(sum>1){
                sum %= 2;
                carry = 1;
            }
            ans = to_string(sum) + ans;
            
            i++;
        }
        
        if(carry){
            ans = "1" + ans;
        }
            
        return ans.empty() ? "0" : ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends