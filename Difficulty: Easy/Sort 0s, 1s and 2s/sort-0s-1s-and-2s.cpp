//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        // 09.09.24 (potd)
        int lo=0, mid=0, hi=arr.size()-1;
        
        while(mid <= hi){
            if(arr[mid] == 0){
                swap(arr[lo], arr[mid]);
                mid++;
                lo++;
            } else if(arr[mid] == 1){
                mid++;
            } else {
                swap(arr[hi], arr[mid]);
                hi--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends