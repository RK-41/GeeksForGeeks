//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here
            // 09.01.24 POTd
            vector<int> ans;
            int p = pat.size();
            int lim = txt.size()-p;
            
            for(int i=0; i<=lim; i++){
                if(txt[i] == pat[0] && txt.substr(i,p) == pat){
                    ans.push_back(i+1);
                }
            }
            
            return (ans.empty() ? vector<int>{-1} : ans);
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        if (res.size()==0)
            cout<<-1<<endl;
        else {
            for (int i : res) cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends