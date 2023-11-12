//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        // 12.11.23 POTD
        
        int n = str1.size(), m = str2.size();
        if(str1.substr(2,n) == str2.substr(0,m-2) && str1.substr(0,2) == str2.substr(m-2,m))
            return true;
        
        if(str2.substr(2,m) == str1.substr(0,n-2) && str2.substr(0,2) == str1.substr(n-2,m))
            return true;
        
            
        return false;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends