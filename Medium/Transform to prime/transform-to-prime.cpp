//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
    {
        // 08.12.23 potd
        
        int sum = accumulate(arr, arr+N, 0);
        
        if(isPrime(sum))
            return 0;
            
        int hans = INT_MAX;
        
        for(int i=sum+1; ; i++){
            if(isPrime(i)){
                hans = i;
                break;
            }
        }
        
        return abs(hans-sum);
    }
    
    bool isPrime(int n){
        if(n==1)    return false;
        
        if(n==2 || n==3)    return true;
        
        if(n%2==0 || n%3==0)
            return false;
            
        for(int i=5; i*i<n; i+=6){
            if(n%i==0 || n%(i+2)==0)
                return false;
        }
        
        return true;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends