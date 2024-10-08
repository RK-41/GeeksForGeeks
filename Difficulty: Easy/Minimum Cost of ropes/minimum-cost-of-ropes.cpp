//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        // 11.09.24 POTD
        long long ans=0;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        
        for(auto a: arr){
            pq.push(a);
        }
        
        while(pq.size() >= 2){
            long long a = pq.top();
            pq.pop();
            long long b = pq.top();
            pq.pop();
            
            a += b;
            ans += a;
            pq.push(a);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends