//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        // 16.10.24 POTD
        int count=0, i=0, n=arr.size();
        
        while(i<n){
            if(arr[i] != i+1){
                swap(arr[i], arr[arr[i]-1]);
                count++;
                if(count > 2)   return false;
            } else {
                i++;
            }
        }
        
        if(count == 0)  return true;
        return count == 2;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends