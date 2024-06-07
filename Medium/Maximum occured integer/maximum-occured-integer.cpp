//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {

        // Your code here
        // 07.06.24 potd
        int ans=0, maxi=0;
        vector<int> fr(maxx+2, 0), prefixSum(maxx+2, 0);
        
        for(int i=0; i<n; i++){
            fr[l[i]]++;
            fr[r[i]+1]--;
        }
        
        for(int i=1; i<=maxx; i++){
            fr[i] += fr[i-1];
        }
        
        for(int i=0; i<=maxx; i++){
            if(fr[i] > maxi){
                maxi = fr[i];
                ans = i;
            }
        }
        
        return ans;
    }
};

/*
1 2 3 4 5
0 0 0 0 0 6 7 8
0 0 3 4 5
1 2 3 4
----------------

2 0 1 -1 -2 1 0 -1

2 2 3 2 0 1 1 0

*/


//{ Driver Code Starts.

int main() {

    int t;

    // taking testcases
    cin >> t;

    while (t--) {
        int n;

        // taking size of array
        cin >> n;
        int l[n];
        int r[n];

        // adding elements to array L
        for (int i = 0; i < n; i++) {
            cin >> l[i];
        }

        int maxx = 0;

        // adding elements to array R
        for (int i = 0; i < n; i++) {

            cin >> r[i];
            if (r[i] > maxx) {
                maxx = r[i];
            }
        }
        Solution ob;

        // calling maxOccured() function
        cout << ob.maxOccured(n, l, r, maxx) << endl;
    }

    return 0;
}
// } Driver Code Ends