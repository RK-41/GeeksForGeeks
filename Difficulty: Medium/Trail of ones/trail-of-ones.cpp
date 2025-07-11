class Solution {
  public:
  // 11.07.25 potd
    int solve(int n , int index){
        if(index>n){
            return 1;
        }
        int res= solve(n,index+1) + solve(n,index+2);
        return res;
    }
    int countConsec(int n) {
        // code here
        int total= 1<<n;
        int noconsecutive = solve(n,1);
        
        int ans=total - noconsecutive;
        
        return ans;
    }
};
