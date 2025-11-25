class Solution {
  public:
    int subarrayXor(vector<int>& arr) {
        // code here
        // 25.11.25 (potd)
        
        int N=arr.size(), xr=0, prev=0, curr=0;
        
        for(int i=0; i<N; i++){
            prev = curr;
            curr = N+prev-2*i;
            
            if(curr%2 != 0)
                xr ^= arr[i];
        }
        
        return xr;
    }
};