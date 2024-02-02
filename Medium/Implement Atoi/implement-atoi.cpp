//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) {
        //Your code here
        // 02.02.24 (potd)
        int ans=0, sign=1, flg=1;
        
        for(int i=0; i<str.length(); i++){
            if(str[0]=='-' && flg){
                sign=-1;
                flg=0;
            }
            else if(str[i]<48 || str[i]>57)
                return -1;
            else
                ans = ans*10 + str[i]-48;
        }
        
        if(sign==-1)
            return sign*ans;
            
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
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends