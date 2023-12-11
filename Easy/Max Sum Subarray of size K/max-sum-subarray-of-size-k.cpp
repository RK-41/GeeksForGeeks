//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        // 11.12.23 POTD
        
        if(K==1)
            return *max_element(Arr.begin(), Arr.end());
            
        long ans=0, curr=0;
    
        for(int i=0; i<K; i++){
            ans += Arr[i];
        }
        
        curr = ans;
        
        for(int i=K; i<N; i++){
            curr = curr+Arr[i]-Arr[i-K];
            
            if(curr>ans){
                ans = curr;
            }
        }
        
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
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends