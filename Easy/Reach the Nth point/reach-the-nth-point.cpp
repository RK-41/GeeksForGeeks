//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int mod=1e9+7;
	    
		int nthPoint(int n){
		    // Code here
		    // 15.05.24 potd
		    
		    if(n==1)    return 1;
		    if(n==2)    return 2;
		    
		    int first=1, second=2;
		    
		    for(int i=3; i<=n; i++){
		        int temp = (first+second)%mod;
		        first = second;
		        second = temp;
		    }
		    
		    return second;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends