//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
        // code here
        // 14.09.23
        
        if(K==1)
            return N/2 + 1;
            
        int i=1, j=N;
        bool turn=0;
        
        while(i<=j-K){
            if(turn==0) // dequeue from left
                i+=K;
            else    // dequeue from right
                j-=K;
            turn = !turn;
        }
        
        
        // if last turn was allotted to right, this means last dequeue was performed 
        // from left which would have made 'i' point to right neighbour of last dequeued element
        if(turn)
            return i;
            
        return j;
        
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends