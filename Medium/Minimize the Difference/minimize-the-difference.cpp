//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        // code here
        // 16.04.24
        int ans=INT_MAX;
        
        vector<int> mnL(n), mnR(n), mxL(n), mxR(n);
        mnL[0]=arr[0], mxL[0]=arr[0];
        // cout<<mnL[0]<<" "<<mxL[0]<<"; ";
        
        for(int i=1; i<n; i++){
            mnL[i] = min(mnL[i-1], arr[i]);
            mxL[i] = max(mxL[i-1], arr[i]);
            // cout<<mnL[i]<<" "<<mxL[i]<<"; ";

        }
        // cout<<endl;
        
        mnR[n-1]=arr[n-1], mxR[n-1]=arr[n-1];
        // cout<<mnR[n-1]<<" "<<mxR[n-1]<<"; ";
        
        for(int i=n-2; i>=0; i--){
            mnR[i] = min(mnR[i+1], arr[i]);
            mxR[i] = max(mxR[i+1], arr[i]);
            // cout<<mnR[i]<<" "<<mxR[i]<<"; ";
        }
        
        int mn = mnR[k], mx = mxR[k];
        ans = min(ans, mx-mn);
        
        // cout<<mn<<" "<<mx<<endl;
        
        int l=1, r=k; // window extremes
        
        while(r<n-1){
            mn = min(mnL[l-1], mnR[r+1]);
            mx = max(mxL[l-1], mxR[r+1]);
            
            ans = min(ans, mx-mn);
            l++, r++;
            // cout<<mn<<" "<<mx<<endl;

        }
        
        mn = mnL[n-k-1], mx = mxL[n-k-1];
        ans = min(ans, mx-mn);
        // cout<<mn<<" "<<mx<<endl;

        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends