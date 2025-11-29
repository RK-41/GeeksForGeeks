class Solution {
  public:
    int countSetBits(int n) {
        // code here
        // 29.11.25 (potd)
        int ans=0;
        
        for(int i=1; i<=n; i<<=1){
            int quot=(n+1)/(i<<1);
            int rem=(n+1)%(i<<1);
            
            ans+=quot*i+max(0,rem-i);
        }
        
        return ans;
    }
};
