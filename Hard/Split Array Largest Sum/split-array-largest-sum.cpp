//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        // 07.01.24 potd
        int start=0, end=accumulate(arr, arr+N, 0);
        int ans;
        
        while(start<=end){
            int mid = (start+end)>>1;
            if(isPossible(arr, K, N, mid)){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        
        return ans;
    }
    
    bool isPossible(int arr[], int k, int n, int minSol){
        int subSum=0, cnt=1;
        
        for(int i=0; i<n; i++){
            if(arr[i] > minSol){
                return false;
            }
                
            if(arr[i] + subSum > minSol){
                cnt++;
                subSum = arr[i];
                if(cnt > k){
                    return false;
                }
            } else {
                subSum += arr[i];
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends