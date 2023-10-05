//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    long long int substrCount (string s, int k) {
    	//code here.
    	// 05.10.23 potd
    	return helper(s,k)-helper(s,k-1);
    }
    
    long long int helper(string s, int k){
        
    	vector<int> mp(26,0);
    	int n=s.size(), j=0, sz=0;
    	long long int ans=0;
    	
    	for(int i=0; i<n; i++){
    	    int idx = s[i]-'a';
    	    
    	    if(mp[idx] == 0)    
    	        sz++;
    	    mp[idx]++;
    	    
    	    while(j<=i and sz>k){
    	        mp[s[j]-'a']--;
    	        if(!mp[s[j]-'a'])
    	            sz--;
    	            
    	        j++;
    	    }
    	    
    	    if(j<=i)
    	        ans += (i-j+1);
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
		string s; cin >> s;
		int k; cin >> k;
		Solution ob;
		cout <<ob.substrCount (s, k) << endl;
	}
}
// } Driver Code Ends