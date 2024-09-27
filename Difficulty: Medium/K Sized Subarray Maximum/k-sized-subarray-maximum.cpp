//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        // 27.09.24 (potd)
        vector<int> ans;
        deque<int> dq;
        int n = arr.size();
        
        for(int i=0; i<k; i++){
            while(dq.size() && dq.back()<arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(arr[i]);
        }
        
        ans.push_back(dq.front());
        
        for(int i=k; i<n; i++){
            if(dq.front() == arr[i-k])
                dq.pop_front();
                
            while(dq.size() && dq.back()<arr[i]){
                dq.pop_back();
            }
            
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends