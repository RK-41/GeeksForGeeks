//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        // 14.11.23 POTD
        
        int n1=s1.size(), n2=s2.size();
        if(n1!=n2)  return false;
        
        vector<int> breakPoints;
        
        for(int i=0; i<n1; i++){
            if(s2[0] == s1[i])
                breakPoints.push_back(i);
        }
        
        for(int i=0; i<breakPoints.size(); i++){
            string str = s1.substr(breakPoints[i], n1) + s1.substr(0, breakPoints[i]);
            
            if(str == s2)   return true;
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends