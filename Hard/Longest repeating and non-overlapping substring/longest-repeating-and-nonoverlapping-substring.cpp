//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string longestSubstring(string s, int n) {
        // code here
        // 07.03.24 potd
        int start=0;
        int end = n%2==0 ? (n/2) : (n/2)+1;
        int mid = (start+end)/2;
        string ans="";
        
        while(start<=end){
            string res = "";
            for(int i=0; i<n; i++){
                string pattern = s.substr(i,mid+1);
                if(pattern.size() < mid+1)
                    break;
                    
                string temp = s.substr(0,i);
                string temp2 = s.substr(i+mid+1, n-(i+mid+1));
                if(temp.find(pattern) != string::npos || temp2.find(pattern) != string::npos){
                    res = pattern;
                    break;
                }
            }
            
            if(res==""){
                end = mid-1;
            } else {
                ans = res;
                start = mid+1;
            }
            
            mid = (start+end)/2;
        }
        
        return ans=="" ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        string S;

        cin >> N;
        cin >> S;

        Solution ob;
        cout << ob.longestSubstring(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends