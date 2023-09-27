//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function teamplate for C++

class Solution{
  public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int x) {
        //code here
        // 27.09.23 potd
        
        int left=0, right=m-1, ans=INT_MAX, a, b;
        
        while(right>=0 and left<n){
            int sum = arr[left] + brr[right];
            if(abs(sum-x) < ans){
                ans = abs(sum-x);
                a = arr[left];
                b = brr[right];
            }
            
            if(sum >= x) right--;
            if(sum < x) left++;
        }
        
        return {a, b};
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	int m,n,x;
	while(t--)
    {
        cin>>n>>m;
        int a[n],b[m];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
            
        for(int i=0;i<m;i++)
            cin>>b[i];
            
        cin>>x;
        
        vector<int> ans;
        Solution ob;
        ans = ob.printClosest(a, b, n, m, x);
        cout << abs(ans[0] + ans[1] - x) << endl;
        
    }
    return 0;
}

// } Driver Code Ends