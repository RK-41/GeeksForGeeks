//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int alternatingMaxLength(vector<int>& arr) {
        // Code here
        // 18.07.24 POTD
        int ans=0, mxLen=1, n=arr.size(), turn=0;
        
        for(int i=0; i<n-1; i++){
            if(turn == 0 && arr[i] < arr[i+1]){
                mxLen++;
                turn = 1;
            } else if(turn == 1 && arr[i] > arr[i+1]){
                mxLen++;
                turn = 0;
            }
        }
        
        ans = max(ans, mxLen);
        mxLen = 1;
        turn = 1;
        
        for(int i=0; i<n-1; i++){
            if(turn == 1 && arr[i] > arr[i+1]){
                mxLen++;
                turn = 0;
            } else if(turn == 0 && arr[i] < arr[i+1]){
                mxLen++;
                turn = 1;
            }
        }   
        
        ans = max(ans, mxLen);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr;
        string temp;
        while (ss >> temp) {
            arr.push_back(stoi(temp));
        }
        Solution obj;
        int ans = obj.alternatingMaxLength(arr);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends