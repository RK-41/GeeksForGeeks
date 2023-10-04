//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        // 04.10.23 
        // rtoi: roman to integer
        unordered_map<string,int> rtoi = {
            {"I",1},
            {"V",5},
            {"X",10},
            {"L",50},
            {"C",100},
            {"D",500},
            {"M",1000}
        };
        // unordered_map<string,int> rtoi = {
        //     {"I",1},
        //     {"IV",4},
        //     {"V",5},
        //     {"IX",9},
        //     {"X",10},
        //     {"XL",40},
        //     {"IL",49},
        //     {"L",50},
        //     {"XC",90},
        //     {"IC",99},
        //     {"C",100},
        //     {"XD",490},
        //     {"ID",499},
        //     {"D",500},
        //     {"XM",990},
        //     {"IM",999},
        //     {"M",1000}
        // };
        
        int ans = 0;
        
        for(int i=0; i<str.size(); i++){
            string s = str.substr(i,1);
            
            if(i<str.size()-1 && rtoi[s]<rtoi[string(1,str[i+1])]){
                ans -= rtoi[s];
                s = str.substr(i+1,1);
                i++;
            }
            ans += rtoi[s];
            // cout<<s<<" "<<ans<<endl;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends