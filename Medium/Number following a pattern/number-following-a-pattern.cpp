//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here 
        // 10.11.23 potd
        
        string ans(1, '1');
        int counter = 0;
        
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'I'){
                ans.push_back(i+2+'0');
                counter = ans.length() - 1;
            } else {
                char temp = i+2+'0';
                string s(1, temp);
                ans.insert(counter, s);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends