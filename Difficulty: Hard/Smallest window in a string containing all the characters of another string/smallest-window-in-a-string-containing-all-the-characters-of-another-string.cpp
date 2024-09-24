//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    string smallestWindow (string s, string p)
    {
        // 24.09.24
        // Approach: Windowing (Expanding to right and Shrinking from left)
        vector<int> mp(256,0);
        int c=0;
        
        for(int i=0; i<p.size(); i++){
            if(mp[p[i]]==0)
                c+=1;
            mp[p[i]]+=1;
        }
        
        int len=INT_MAX;
        int st=0, i=0, j=0;
        while(j<s.size()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                c-=1;
            if(c==0){
                // shrinking the window while c==0
                while(c==0){
                    if((j-i+1 < len)){
                        len = j-i+1;
                        st=i;
                    }
                    mp[s[i]]++;
                    if(mp[s[i]]==1)
                        c+=1;
                    i+=1;
                }
            }
            j+=1;
        }
        
        if(len != INT_MAX)  
            return s.substr(st,len);
        
        return "-1";
    }
};


//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends