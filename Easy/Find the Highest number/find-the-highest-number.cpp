//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int findPeakElement(vector<int>& a) 
    {
        // Code here.
        // 18.05.24 POTD
        
        int n=a.size();
        
        if(a[n-1] > a[n-2])
            return a[n-1];
            
        int l=0, r=n-1, m;
        while(l<=r){
            m = l + (r-l)/2;

            if(m<n-1 && a[m]>a[m+1] && m>0 && a[m]>a[m-1])
                return a[m];
            else if(a[m]<a[m+1])
                l++;
            else
                r--;
        }
        
        return a[m];
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
    	vector<int>a(n);
    	for(int i = 0; i < n; i++)
    		cin>>a[i];
    	Solution ob;
    	int ans = ob.findPeakElement(a);
    	cout << ans << "\n";
    }
	return 0;
}


// } Driver Code Ends