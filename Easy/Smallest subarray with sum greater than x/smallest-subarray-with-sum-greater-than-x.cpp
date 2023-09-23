//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
        // 23.09.23
        int i=0, j=0, ans=INT_MAX, sum=0;
        
        while(true){
            if(sum <= x and j<n){
                sum += arr[j];
                j++;
            }
            else if(sum <= x and j>=n){
                break;
            }
            else if(sum > x){
                sum -= arr[i];
                ans = min(ans, j-i);
                i++;
            }
        }
        
        if(i==0 and j>=0)   return 0;
        
        return ans;
        
        
        
        // while(i<=j && j<n-1){
        //     if(arr[j]>x){
        //         ans = min(ans,j-i+1);
        //         arr[j] -= arr[i];
        //         i++;
        //     }
        //     else{
        //         // if(j<n-1)
        //             arr[j+1] += arr[j];
        //         j++;
        //     }
        // }
        
        // while(arr[n-1]>x && i<n){
        //         ans = min(ans,j-i+1);
        //         arr[j] -= arr[i];
        //         i++;
        //     }
        
        // return ans==INT_MAX ? 0:ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends