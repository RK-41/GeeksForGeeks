//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    string colName (long long int n)
    {
        // your code here
        // 03.10.23 
        
        string ans;
        
        while(n>0){
            int m = n%26;
            
            if(m==0){
                m=26;
                n--;
            }
            ans =  (char)(64+m) + ans;
        
            n /= 26;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
	{
		long long int n; cin >> n;
		Solution ob;
		cout << ob.colName (n) << '\n';
	}
}

// } Driver Code Ends