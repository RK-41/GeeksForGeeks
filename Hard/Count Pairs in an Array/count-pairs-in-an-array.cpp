//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// Defining a data structure pbds using GNU pb_ds
typedef tree<long long, null_type, greater_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> pbds;

class Solution{
    public:
    int countPairs(int arr[] , int n ) 
    {
        // Your code goes here   
        // 17.04.24 potd
        int ans=0;
        pbds st;
        
        // Multiply each element of the array with its index
        for(int i=0; i<n; i++){
            arr[i] *= i;
        }
        
        for(int i=0; i<n; i++){
            // Add the number of elements greater than or equal to arr[i] in the pbds tree to the answer
            ans += st.order_of_key(arr[i]);
            st.insert(arr[i]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends