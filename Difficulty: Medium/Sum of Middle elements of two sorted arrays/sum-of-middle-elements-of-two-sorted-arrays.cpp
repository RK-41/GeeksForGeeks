//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

//Position this line where user code will be pasted.
class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {
        // code here
        // 12.08.24 POTD
        int ans=0, n=arr1.size(), i=0, j=0;
        int countDown = n - 1;
        
        while(i<n || j<n){
            if(countDown<=0){
                if(arr1[i] < arr2[j])
                    ans += arr1[i];
                else
                    ans += arr2[j];
                
                if(countDown == -1)
                    break;
            }  
            
            if(i<n && j<n){
                if(arr1[i] < arr2[j])
                    i++;
                else
                    j++;
            } else if(i<n){
                i++;
            } else {
                j++;
            }
            
            countDown--;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
//Back-end complete function template in C++

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}
// } Driver Code Ends