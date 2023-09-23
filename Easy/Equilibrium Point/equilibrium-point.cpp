//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
    
        // Your code here
        // 23.09.23 POTD
        if(n==1)    return 1;
        
        int i=0, j=n-1;
        
        while(i<=j){
            if(a[i]==a[j] && j-i==2){
                return j;
            }
            else if(a[i] < a[j]){
                a[i+1] += a[i];
                i++;
            }
            else if(a[i] > a[j]){
                a[j-1] += a[j];
                j--;
            }
            else{
                a[i+1] += a[i];
                i++;
                
                a[j-1] += a[j];
                j--;
            }
        }
        
        return -1;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends