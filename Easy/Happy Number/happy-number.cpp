//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int N){
        // code here
        // 11.09.23
        
        if(N==1 || N==10)   return true;
        
        unordered_map<int,int> sq;
        set<int> st;
        
        for(int i=1; i<10; i++){
            sq[i] = i*i;
        }
        
        while(true){
            if(st.find(N) != st.end())
                return false;
               
            st.insert(N);
            
            int dss=0;
            // dss: digit-sq-sum
            
            while(N > 0){
                dss += sq[N%10];
                N/=10;
            }
            
            if(dss==1 || dss==10)
                return true;
                
            N = dss;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends