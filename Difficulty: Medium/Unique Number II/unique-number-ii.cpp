//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
public:
    vector<int> singleNum(vector<int> nums) 
    {
        // Code here.
        // 14.08.23 (potd)
        
        vector<int> ans;
        set<int> s;
        for(int i=0; i<nums.size(); i++){
            if(s.find(nums[i])!=s.end())
                s.erase(s.find(nums[i]));
            else
                s.insert(nums[i]);
        }
        
        for(auto it:s)
            ans.push_back(it);
            
        return ans;
    }
};



//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends