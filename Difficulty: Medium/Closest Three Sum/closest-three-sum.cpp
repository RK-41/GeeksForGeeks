//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        // 09.07.24 POTd
        int ans=INT_MIN, diff=INT_MAX, n=arr.size();
        
        sort(arr.begin(), arr.end());
        
        for(int i=0; i<n-2; i++){
            int sum = 0;
            int l=i+1, r=n-1;
            
            while(l < r){
                sum = arr[i] + arr[l] + arr[r];
                int d = abs(target - sum);
                
                if(d == diff){
                    ans = max(ans, sum);
                } else if(d < diff){
                    ans = sum;
                    diff = d;
                }
                
                if(sum < target){
                    l++;
                } else {
                    r--;
                }
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
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends