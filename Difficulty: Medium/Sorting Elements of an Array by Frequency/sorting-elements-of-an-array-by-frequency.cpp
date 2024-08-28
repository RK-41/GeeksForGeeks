//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        //Your code here
        // NICE APPROACH
        // DECREMENTING THE COUNT SO THAT HIGHEST FREQUENCY COMES
        // FIRST WITH NEGATIVE SIGN AND MULTIPLYING -1 TO MAKE IT POSITIVE
        // 28.08.24 (potd)
        
        map<int,int> mp;
        multimap<int,int> mm;
        vector<int> ans;
        int n = arr.size();
        
        for(int i=0; i<n; i++)
            mp[arr[i]]--;
            
        for(auto x: mp)
            mm.insert(pair<int,int>(x.second,x.first));
            
        for(auto x: mm){
            int i=-1*x.first;
            int a=x.second;
            
            while(i--)
                ans.push_back(a);
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends