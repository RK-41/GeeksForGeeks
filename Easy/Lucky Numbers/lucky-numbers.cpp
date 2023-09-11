//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False
// https://practice.geeksforgeeks.org/problems/lucky-numbers2911/1
class Solution{
public:
    bool isLucky(int n, int count=2) {
        // code here
        // 11.09.23 potd
        
        // if n is divisible by count it means n is deleted
        if(n%count==0)  return false;
        
        // (n<count): n survived the deletion
        if(n<count) return true;
        
        return isLucky((n-(n/count)),count+1);
        // remaining number = n - (n/count)
        // (n/count): deleted number
        // (count+1): count is increased as per problem
    }
};

//{ Driver Code Starts.
signed main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        Solution obj;
        //calling isLucky() function
        if(obj.isLucky(n))
            cout<<"1\n";//printing "1" if isLucky() returns true
        else
            cout<<"0\n";//printing "0" if isLucky() returns false
    }
    
}
// } Driver Code Ends