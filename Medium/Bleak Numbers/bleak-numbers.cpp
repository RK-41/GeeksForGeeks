//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
	int is_bleak(int n)
	{
	    // Code here.
	    // 28.10.23 POTD
	    
	    int x = n;
	    
	    while(x >= (n-log2(n))){
	        if((x + __builtin_popcount(x)) == n)
	            return 0;
	           
	        x--;
	    }
	    
	    return 1;
	    
	    /*  
	        '__builtin_popcount(x)' returns the number of set bits in the
	            binary representation of the integer 'x'.
	    
	    */
	}
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	Solution ob;
    	int ans = ob.is_bleak(n);
    	cout << ans << "\n";
    }
	return 0;
}

// } Driver Code Ends