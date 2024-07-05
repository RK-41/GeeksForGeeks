//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    int solve(int n, int k, vector<int> &stalls) {
        // Write your code here
        // 05.07.24 
        sort(stalls.begin(), stalls.end());
        
        int lo=1, hi=(stalls.back()-stalls[0])/(k-1);
        
        while(lo <= hi){
            int mid = lo + (hi-lo)/2;
            
            if(placementPossible(k, stalls, n, mid))
                lo = mid+1;
            else
                hi = mid-1;
        }
        
        return hi;
    }
    
    bool placementPossible(int k, vector<int>& stalls, int n, int dist){
        int count=1, lastStall=stalls[0];
        
        for(int i=1; i<n; i++){
            if(stalls[i] - lastStall >= dist){
                lastStall = stalls[i];
                count++;
            }
            
            if(count == k)
                return true;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends