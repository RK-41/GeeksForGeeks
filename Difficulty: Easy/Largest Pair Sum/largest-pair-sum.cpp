//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        // 08.10.24 POTD
        int a=arr[0], b=arr[1], n=arr.size();
        
        for(int i=1; i<n; i++){
            if(arr[i] > a){
                if(a > b || arr[i] == b){
                    b = a;
                }
                a = arr[i];
            } else if(arr[i] > b){
                b = arr[i];
            }
        }
        
        return a+b;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends