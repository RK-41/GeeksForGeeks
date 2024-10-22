//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        // 22.10.24 pot
        int ans=0, count=0;
        map<int,int> mp;
        mp[0] = 1;
        
        for(auto a: arr){
            if(a == x)  count++;
            if(a == y)  count--;
            if(mp[count])   ans += mp[count];
            mp[count] += 1;
        }
        
        return ans;
        
        // APPROACH 1: Not perfect
        // vector<int> occurX(n), occurY(n);
        
        // if(arr[0] == x){
        //     occurX[0]++;
        // } else if(arr[0] == y){
        //     occurY[0]++;
        // }
        
        // for(int i=1; i<n; i++){
        //     if(arr[i] == x){
        //         occurX[i] = occurX[i-1] + 1;
        //         occurY[i] = occurY[i-1];
        //     } else if(arr[i] == y){
        //         occurY[i] = occurY[i-1] + 1;
        //         occurX[i] = occurX[i-1];
        //     }
        // }
        
        // for(int i=0; i<n; i++){
        //     for(int j=i; j<n; j++){
        //         if(i==0){
        //             ans += (occurX[j] == occurY[j]);
        //             continue;
        //         }
                
        //         ans += ((occurX[j] - occurX[i-1]) == (occurY[j] - occurY[i-1]));
        //     }
        // }
        
        // return ans;
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
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends